# SmartSort Paper Pro — Estación Automatizada de Reciclaje de Papel

> **Proyecto de Robótica y Tecnología — Grado 10-01**  
> 🌐 **Simulador 3D Interactivo en vivo:** [https://jupa-02.github.io/Ptoyecto-basurero/](https://jupa-02.github.io/Ptoyecto-basurero/)

---

## 👥 Equipo de Trabajo (Grado 10-01)

* **Paula Andrea Bohórquez Díaz**
* **Ana María Infante Mendoza**
* **Dariana Isabel Rentería Puello**
* **Samuel David Lambraño Núñez**
* **Denzel David Luna López**
* **Adrián Esteban Caro Romero**

---

## 📋 Descripción del Proyecto

**SmartSort Paper Pro** es un prototipo de estación robótica e interactiva diseñada específicamente para resolver uno de los mayores problemas en la cadena de reciclaje: **la contaminación del papel aprovechable con residuos húmedos u orgánicos**.

Cuando el papel se moja, sus fibras de celulosa se degradan y pierde su valor para el reciclaje industrial. Este sistema automatizado clasifica en tiempo real el papel insertado, enviando el **papel seco al compartimento de reciclaje (02)** y el **papel húmedo o contaminado al compartimento no reciclable (01)** mediante una compuerta basculante servocontrolada.

---

## ⚙️ Componentes y Arquitectura de Hardware

1. **Cerebro del Sistema:** Microcontrolador **Arduino Uno R3** (ATmega328P).
2. **Detección de Presencia / Enfoque:** Sensor ultrasónico **HC-SR04** (detección sin contacto en la tolva superior).
3. **Discriminación de Humedad:** Sensor resistivo de conductividad con electrodos dorados en la rampa de pesaje/contacto.
4. **Mecanismo Actuador:** Servomotor **TowerPro SG90** (giro angular bidireccional: $\pm 35^\circ$ hacia tolva húmeda o seca).
5. **Estructura:** Kiosco industrial abierto con pilares cilíndricos de aluminio cepillado, rampa de acero inoxidable y compuertas frontales serigrafiadas con vidrio ahumado.

---

## 📂 Estructura del Repositorio

```text
├── index.html                     # Simulador 3D interactivo listo para GitHub Pages
├── Codigo_Arduino/
│   └── caneca_robot.ino           # Firmware completo para Arduino Uno
├── Documentacion_y_Exposicion/
│   └── GUIA_EXPOSICION_GRUPO_10_01.md  # Libreto de sustentación técnica y preguntas
├── Renders_3D/                    # Vistas y cortes esquemáticos del prototipo
├── Simulador_3D_Interactivo/      # Archivos fuente del entorno WebGL/Three.js
└── ABRIR_EN_CELULAR.command       # Lanzador local para pruebas offline
```

---

## 🚀 Cómo Usar el Simulador 3D

1. Abre el enlace directo: [https://jupa-02.github.io/Ptoyecto-basurero/](https://jupa-02.github.io/Ptoyecto-basurero/)
2. **Interacción 3D:**
   * Gira la cámara en 360° con un dedo (o clic izquierdo).
   * Haz zoom o desplázate con dos dedos.
   * Cambia de perspectiva con el botón superior **[📷 Vistas]**.
3. **Simulación de Reciclaje:**
   * Presiona **`01 Tiras Húmedo`**: Observa cómo el residuo cae en los electrodos, el servo inclina la rampa a la izquierda y se abre la compuerta de residuo húmedo.
   * Presiona **`02 Tiras Seco`**: Observa cómo detecta resistencia infinita, inclina la rampa a la derecha y deposita el papel en el contenedor de reciclaje limpio.
   * Presiona **`▶ Modo Auto`** para una demostración continua durante la exposición.
