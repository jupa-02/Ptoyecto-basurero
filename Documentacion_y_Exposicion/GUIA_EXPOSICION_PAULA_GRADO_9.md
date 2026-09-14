# Guía de Exposición y Sustentación Técnica: SmartSort Paper Pro
**Sistema:** Estación Inteligente de Clasificación de Papel (Edición Rosado Mate & Aluminio Anodizado)  
**Área:** Ciencias, Robótica y Sostenibilidad Ambiental  

---

## 1. El Problema Real que Resuelve el Proyecto
En colegios, oficinas y bibliotecas, **el papel representa más del 65% de todos los residuos sólidos**. Aunque existan canecas para papel, el sistema de reciclaje fracasa por una causa crítica:
- **La contaminación por humedad:** Cuando una persona arroja una servilleta grasienta, una toalla de papel húmeda o una hoja manchada con café o jugo en la caneca de papel limpio, **el agua rompe los enlaces de hidrógeno de la celulosa**.
- Se produce una pasta con hongos y moho que **arruina pacas enteras de papel reciclable** y atasca las cribas industriales en los molinos de pulpa.
- **Nuestra solución tecnológica:** Una estación inteligente especializada exclusivamente en papel que no depende del juicio de las personas. La caneca analiza en tiempo real la impedancia eléctrica de las fibras celulósicas y activa un servomotor para desviar automáticamente el papel seco al contenedor de reciclaje virgen y el papel mojado al contenedor de descarte.

---

## 2. Los 4 Componentes Electrónicos de Ingeniería

| Componente | Función en la Estación | Principio Físico / Científico |
| :--- | :--- | :--- |
| **Arduino Uno R3** | Unidad de Procesamiento Central (CPU) | Microcontrolador ATmega328P a 16 MHz que ejecuta la lógica comparativa condicional (`if/else`) y modula pulsos PWM para el servomotor. |
| **Sensor Ultrasónico (HC-SR04)** | Detección de presencia y aproximación | Emite ondas sonoras a 40.000 Hz. Calcula la distancia según el tiempo de vuelo del eco: $d = \frac{v \times t}{2}$, detectando la mano a menos de 14 cm. |
| **Sensor de Conductividad Celulósica** | Matriz de pistas doradas en la bandeja | **Propiedad dieléctrica del papel:** El papel seco es aislante (resistencia > 10 MΩ, lectura analógica A0 < 250). El papel húmedo contiene agua e iones libres que conducen electrones (A0 > 250). |
| **Servomotor Micro SG90 (9g)** | Actuador mecánico de desvío angular | Convierte el ancho de pulso eléctrico (PWM de 1.0 ms a 2.0 ms) en un ángulo de giro exacto: inclina la rampa 40° a la izquierda (01 Húmedo) o 40° a la derecha (02 Seco). |

---

## 3. Guion Paso a Paso para la Exposición (Duración: 3 a 4 Minutos)

### Paso 1: Introducción y Planteamiento del Problema (45 segundos)
> *"Buenos días profesor y compañeros. Hoy les presento mi proyecto de innovación tecnológica: la **Estación Inteligente de Clasificación de Papel SmartSort Paper Pro**.*  
> *En los colegios generamos miles de hojas de papel reciclable, pero un solo papel con restos de comida o una servilleta mojada contamina todo el contenedor, rompiendo las fibras de celulosa y haciendo imposible su reprocesamiento en los molinos de papel.*  
> *Para solucionar este problema sin depender del error humano, diseñé un kiosco automatizado con sensores de conductividad y servomecanismo que separa el papel húmedo del papel seco en menos de dos segundos."*

### Paso 2: Diseño Industrial y Estructura Mecánica (1 minuto)
> *(Muestras los Renders 3D en pantalla o en el celular)*  
> *"La estación está construida con un chasis en acabado rosado mate electrostático con perfiles de aluminio anodizado y compuertas inferiores de vidrio ahumado etiquetadas como **01: Papel Húmedo** y **02: Papel Seco**.*  
> *En la boca de recepción abierta se encuentra una bandeja de acero inoxidable pulido acoplada al eje de un servomotor SG90. En el centro de la rampa se integra una placa sensora con pistas doradas de contacto directo que miden las propiedades eléctricas del residuo."*

### Paso 3: Demostración en Vivo con el Simulador 3D (1.5 minutos)
> *(Abres `Simulador_3D_Interactivo/index.html` en el celular o la computadora)*  
> 1. *"Profesor, aquí podemos observar el modelo 3D en tiempo real con iluminación de estudio."*  
> 2. *(Presionas el botón **00: Sensor Ultrasónico**)*:  
>    *"Al acercar la mano a menos de 14 cm, el sensor HC-SR04 despierta el sistema para recibir el papel."*  
> 3. *(Presionas **01: Papel Húmedo / Servilleta**)*:  
>    *"Si arrojamos una servilleta o papel mojado, el agua y las sales conducen electricidad. El pin analógico A0 sube a 792. El Arduino diagnostica 'Papel No Reciclable', el servomotor inclina la rampa a 45° a la izquierda, la compuerta 01 se abre y el desecho cae al compartimento de descarte."*  
> 4. *(Presionas **02: Papel Seco / Hoja Limpia**)*:  
>    *"Si arrojamos una hoja seca de cuaderno, el papel actúa como aislante dieléctrico con lectura baja de 22. El Arduino confirma fibra celulósica limpia, el servo inclina la rampa a 135° a la derecha y el papel entra al contenedor 02 de reciclaje 100% puro."*

### Paso 4: Conclusión (30 segundos)
> *"Con este proyecto demostramos cómo la mecatrónica aplicada a un problema cotidiano como la recolección de papel puede salvar toneladas de celulosa limpia y optimizar la economía circular en nuestra institución. Muchas gracias."*

---

## 4. Preguntas Difíciles del Profesor y Cómo Responder con Nivel Científico

### Pregunta 1: "¿Por qué el agua hace que el papel deje de ser reciclable?"
- **Respuesta científica:**  
  *"El papel se mantiene unido gracias a puentes de hidrógeno entre las microfibras de celulosa. Cuando entra en contacto con agua y grasas, estos enlaces moleculares se rompen y las fibras se deshilachan irreversiblemente. Además, si se almacena papel mojado en un contenedor cerrado, en 48 horas proliferan hongos y bacterias que pudren el papel seco adyacente."*

### Pregunta 2: "¿Cómo distingue el sensor si el papel está seco o mojado si el papel no es metal?"
- **Respuesta científica:**  
  *"El papel seco es un excelente material dieléctrico (aislante eléctrico) con resistencia superior a 10 megaohmios, por lo que la corriente no fluye entre las pistas doradas del sensor. Sin embargo, el agua no está químicamente pura; contiene sales disueltas e iones libres que permiten el flujo de electrones. Al colocar el papel mojado sobre el sensor, se cierra el circuito y el voltaje medido por el convertidor análogo-digital (ADC) del Arduino en el pin A0 se eleva drásticamente."*

### Pregunta 3: "¿Por qué la rampa vuelve a 90 grados después de descargar?"
- **Respuesta científica:**  
  *"Porque el servomotor está programado en bucle cerrado (closed-loop) mediante pulsos PWM de 1.5 milisegundos que corresponden a la posición neutral de 90°. Una vez transcurre el temporizador de caída por gravedad de 2.5 segundos, el microcontrolador restablece la rampa a su plano horizontal para esperar la siguiente hoja."*

---

## 5. Tabla de Conexiones de Circuito (Pinout Oficial)

| Módulo / Dispositivo | Pin del Módulo | Pin Arduino Uno | Función Técnica |
| :--- | :--- | :--- | :--- |
| **Sensor Ultrasónico HC-SR04** | VCC | 5V | Alimentación de voltaje continuo |
| | GND | GND | Tierra común de referencia |
| | Trig | Pin 2 | Emisión de ráfaga sonora a 40 kHz |
| | Echo | Pin 3 | Detección de eco reflejado |
| **Sensor de Fibra de Papel** | VCC | 5V | Voltaje de referencia |
| | GND | GND | Tierra |
| | A0 | Pin A0 | Señal analógica de impedancia (0 a 1023) |
| **Servomotor SG90 (9g)** | Cable Rojo | 5V | Alimentación del motor |
| | Cable Café/Negro | GND | Tierra |
| | Cable Naranja/Amarillo | Pin 9 | Señal de modulación por ancho de pulsos (PWM) |
| **Buzzer Piezoeléctrico** | Positivo (+) | Pin 7 | Generación de frecuencias de tono audibles |
| | Negativo (-) | GND | Tierra |
