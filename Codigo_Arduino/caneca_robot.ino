/*
  =============================================================================
  PROYECTO DE INNOVACIÓN TECNOLÓGICA Y SOSTENIBILIDAD — GRADO 10-01
  SISTEMA: ESTACIÓN INTELIGENTE DE SEPARACIÓN DE PAPEL (SMARTSORT PAPER PRO)
  =============================================================================
  
  INTEGRANTES DEL EQUIPO (CURSO 10-01):
  - Paula Andrea Bohórquez Díaz
  - Ana María Infante Mendoza
  - Dariana Isabel Rentería Puello
  - Samuel David Lambraño Núñez
  - Denzel David Luna López
  - Adrián Esteban Caro Romero

  OBJETIVO TÉCNICO:
  Resolver la contaminación en la cadena de reciclaje de papel en instituciones.
  El papel húmedo o contaminado con líquidos pierde la cohesión de sus fibras de
  celulosa por ruptura de puentes de hidrógeno, generando hongos y atascando los
  molinos de pulpa. Un solo papel mojado arruina lotes enteros de papel limpio.

  FUNCIONAMIENTO MECATRÓNICO:
  1. Sensor Ultrasónico HC-SR04: Detecta la aproximación de la mano (< 15 cm).
  2. Sensor de Conductividad Celulósica: Mide la impedancia en el Pin A0.
     - Papel Seco: Dieléctrico con resistencia infinita (A0 < 250).
     - Papel Húmedo: Iones disueltos conducen corriente (A0 >= 250).
  3. Servomotor SG90 (9g): Bascula la rampa de acero inoxidable hacia:
     - Izquierda (45°): Compartimento 01 (Papel Húmedo / No Reciclable).
     - Derecha (135°): Compartimento 02 (Papel Seco / 100% Reciclable).
  =============================================================================
*/

#include <Servo.h>

// --- ASIGNACIÓN DE PINES ---
const int PIN_TRIG          = 2;   // Disparo de pulso ultrasónico (Trigger)
const int PIN_ECHO          = 3;   // Recepción de eco ultrasónico (Echo)
const int PIN_SENSOR_FIBRA  = A0;  // Entrada analógica de conductividad de papel
const int PIN_SERVO         = 9;   // Señal PWM de control del servomotor
const int PIN_LED_HUMEDO    = 4;   // Indicador Compartimento 01 (Húmedo)
const int PIN_LED_SECO      = 5;   // Indicador Compartimento 02 (Seco)
const int PIN_LED_ESTADO    = 6;   // Indicador de detección / Sistema listo
const int PIN_BUZZER        = 7;   // Notificación acústica piezoeléctrica

// --- PARÁMETROS DE CALIBRACIÓN ---
const int DISTANCIA_UMBRAL_CM   = 14;  // Distancia máxima de activación (cm)
const int UMBRAL_HUMEDAD_PAPEL  = 250; // Umbral de conductividad iónica
const int ANGULO_REPOSO         = 90;  // 90°: Rampa horizontal equilibrada
const int ANGULO_PAPEL_HUMEDO   = 45;  // 45°: Desvío a la izquierda (01 Húmedo)
const int ANGULO_PAPEL_SECO     = 135; // 135°: Desvío a la derecha (02 Seco)
const unsigned long TIEMPO_CAIDA = 2500; // Tiempo para permitir la descarga (ms)

Servo servoRampa;

void setup() {
  Serial.begin(9600);
  Serial.println(F("=== SMARTSORT PAPER PRO: SISTEMA INICIADO ==="));

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_SENSOR_FIBRA, INPUT);
  pinMode(PIN_LED_HUMEDO, OUTPUT);
  pinMode(PIN_LED_SECO, OUTPUT);
  pinMode(PIN_LED_ESTADO, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // Inicialización del servomotor en reposo horizontal
  servoRampa.attach(PIN_SERVO);
  servoRampa.write(ANGULO_REPOSO);

  // Autodiagnóstico de encendido
  emitirTono(1200, 100);
  digitalWrite(PIN_LED_ESTADO, HIGH);
  delay(150);
  digitalWrite(PIN_LED_ESTADO, LOW);
}

void loop() {
  // 1. Monitoreo de proximidad con el sensor ultrasónico
  long distancia = medirDistanciaCm();

  if (distancia > 0 && distancia <= DISTANCIA_UMBRAL_CM) {
    Serial.print(F("[PROXIMIDAD] Usuario detectado a "));
    Serial.print(distancia);
    Serial.println(F(" cm."));

    digitalWrite(PIN_LED_ESTADO, HIGH);
    emitirTono(1760, 60);

    // Pausa técnica para permitir que la persona deposite la hoja en la bandeja
    Serial.println(F("[ESPERA] Recepción de hoja de papel..."));
    delay(1800);

    // 2. Muestreo de conductividad en las fibras de papel
    int lecturaFibra = promediarLecturasHumedad(6);
    Serial.print(F("[MEDICIÓN A0] Valor analógico de impedancia: "));
    Serial.println(lecturaFibra);

    // 3. Clasificación celulósica y acción mecánica
    if (lecturaFibra >= UMBRAL_HUMEDAD_PAPEL) {
      // PAPEL HÚMEDO / CONTAMINADO
      Serial.println(F("-> DIAGNÓSTICO: PAPEL HÚMEDO (Descarte / No Reciclable)"));
      digitalWrite(PIN_LED_HUMEDO, HIGH);
      emitirTono(650, 250);

      // Bascular rampa a la izquierda (Compartimento 01)
      posicionarRampaSuave(ANGULO_PAPEL_HUMEDO);
      delay(TIEMPO_CAIDA);
      digitalWrite(PIN_LED_HUMEDO, LOW);

    } else {
      // PAPEL SECO / FIBRA VIRGEN LIMPIA
      Serial.println(F("-> DIAGNÓSTICO: PAPEL SECO (100% Reciclable)"));
      digitalWrite(PIN_LED_SECO, HIGH);
      emitirTono(1050, 150);
      delay(50);
      emitirTono(1320, 150);

      // Bascular rampa a la derecha (Compartimento 02)
      posicionarRampaSuave(ANGULO_PAPEL_SECO);
      delay(TIEMPO_CAIDA);
      digitalWrite(PIN_LED_SECO, LOW);
    }

    // 4. Retorno a reposo y rearme del sistema
    Serial.println(F("[RETORNO] Rampa restablecida a 90°."));
    posicionarRampaSuave(ANGULO_REPOSO);
    digitalWrite(PIN_LED_ESTADO, LOW);
    delay(1000);
  }

  delay(60);
}

// --- FUNCIONES TÉCNICAS AUXILIARES ---

long medirDistanciaCm() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(4);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Velocidad del sonido en aire: 343 m/s (29.2 microsegundos por centímetro)
  long duracionPulso = pulseIn(PIN_ECHO, HIGH, 25000); // Timeout 25ms
  if (duracionPulso == 0) return 999;
  return duracionPulso / 29 / 2;
}

int promediarLecturasHumedad(int muestras) {
  long suma = 0;
  for (int i = 0; i < muestras; i++) {
    suma += analogRead(PIN_SENSOR_FIBRA);
    delay(20);
  }
  return (int)(suma / muestras);
}

void posicionarRampaSuave(int anguloObjetivo) {
  int anguloActual = servoRampa.read();
  int paso = (anguloActual < anguloObjetivo) ? 2 : -2;

  while (abs(anguloActual - anguloObjetivo) > 2) {
    anguloActual += paso;
    servoRampa.write(anguloActual);
    delay(18); // Control de inercia y velocidad angular
  }
  servoRampa.write(anguloObjetivo);
}

void emitirTono(int frecuenciaHz, int duracionMs) {
  tone(PIN_BUZZER, frecuenciaHz, duracionMs);
}
