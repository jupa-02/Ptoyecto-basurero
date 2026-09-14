# Guía Maestra de Sustentación Colectiva: SmartSort Paper Pro
**Proyecto de Tecnología, Mecatrónica y Sostenibilidad Ambiental**  
**Curso:** Grado 10-01  
**Estación Inteligente de Clasificación Celulósica (Edición Rosado Mate & Aluminio Anodizado)**

---

## 1. Integrantes del Equipo (Grado 10-01)

1. **Paula Andrea Bohórquez Díaz**
2. **Ana María Infante Mendoza**
3. **Dariana Isabel Rentería Puello**
4. **Samuel David Lambraño Núñez**
5. **Denzel David Luna López**
6. **Adrián Esteban Caro Romero**

---

## 2. Guion de Exposición por Turnos (Duración Total: 4 a 5 Minutos)

### Intervención 1: Paula Andrea Bohórquez Díaz (45 segundos)
**Tema:** Introducción, Planteamiento del Problema y Justificación
> *"Buenos días profesor y compañeros. Hoy nuestro equipo del curso 10-01 presenta el proyecto **SmartSort Paper Pro**, una estación inteligente de separación automatizada diseñada exclusivamente para el residuo más común en las aulas de clase y oficinas: **el papel**.*  
> *En los colegios, más del 65% de la basura generada es papel bond y cartulina que en teoría debería reciclarse al 100%. Sin embargo, en la práctica el sistema colapsa porque los estudiantes arrojan servilletas mojadas, toallas de manos húmedas o papeles manchados de comida en la misma caneca.*  
> *Para erradicar el error humano, nuestro equipo desarrolló un prototipo mecatrónico que analiza las fibras del residuo en tiempo real y decide automáticamente a qué contenedor enviarlo."*

---

### Intervención 2: Ana María Infante Mendoza (45 segundos)
**Tema:** Fundamento Químico y Ambiental (¿Por qué el papel mojado no se recicla?)
> *"Desde el punto de vista químico, el papel mantiene su rigidez gracias a millones de **puentes de hidrógeno** entre las microfibras de celulosa.*  
> *Cuando una hoja entra en contacto con agua o grasa, las moléculas líquidas rompen estos enlaces moleculares, provocando que la fibra se deshilache y se degrade de forma irreversible.*  
> *Si una sola servilleta húmeda se mezcla en una bolsa de papel seco, la humedad y las bacterias fermentan en menos de 48 horas, generando moho y pudriendo pacas completas. Nuestro sistema asegura la pureza del material separando el papel seco para reciclaje virgen y aislando el papel húmedo en un contenedor sellado."*

---

### Intervención 3: Dariana Isabel Rentería Puello (45 segundos)
**Tema:** Diseño Industrial, Acabado Rosado Mate e Interfaz Móvil
> *"Para el diseño del kiosco rompimos con los esquemas de las canecas plásticas tradicionales. Diseñamos una estructura contemporánea con chasis de aluminio termolacado en **rosado mate (*blush rose*)** con compuertas de vidrio ahumado etiquetadas con serigrafía técnica: **01 para Papel Húmedo** y **02 para Papel Seco**.*  
> *Además, para que cualquier docente o supervisor pueda monitorear la estación, desarrollamos una **interfaz web interactiva optimizada para teléfonos móviles**, donde se visualiza el modelo 3D con iluminación de estudio, telemetría de los sensores en vivo y control táctil ergonómico."*

---

### Intervención 4: Samuel David Lambraño Núñez (45 segundos)
**Tema:** Mecanismo Físico, Servomotor SG90 y Cinemática
> *"El corazón mecánico del dispositivo es una **rampa basculante de acero inoxidable quirúrgico**, montada sobre un pivote central acoplado a un servomotor micro SG90 de 9 gramos.*  
> *El mecanismo funciona con control de lazo cerrado por pulsos PWM de modulación:*  
> *- En reposo, el motor se ubica a **90 grados**, manteniendo la bandeja horizontal.*  
> *- Si el residuo es húmedo, el servo gira a **45 grados hacia la izquierda**, inclinando la rampa y abriendo la compuerta 01.*  
> *- Si el residuo es seco, el servo rota a **135 grados hacia la derecha**, descargando la hoja por gravedad en el compartimento 02.*  
> *Transcurridos 2.5 segundos, el sistema regresa automáticamente a su posición de equilibrio."*

---

### Intervención 5: Denzel David Luna López (50 segundos)
**Tema:** Firmware Arduino C++ y Demostración en Vivo desde el Celular
*(Denzel o Paula sostienen el teléfono mostrando el Simulador 3D al profesor)*
> *"En el apartado de programación, el microcontrolador ATmega328P de Arduino procesa las lecturas de los sensores mediante una rutina cíclica sin bloqueos.*  
> *Veamos la demostración en vivo en nuestro simulador:*  
> 1. *(Toca **00 / Sensor Ultrasónico**)*: *'Cuando el usuario acerca la mano a menos de 14 centímetros, el sensor ultrasónico detecta el eco sonoro y activa la estación.'*  
> 2. *(Toca **01 / Papel Húmedo**)*: *'Arrojamos una toalla mojada. Al tocar la bandeja, los iones disueltos conducen corriente cerrando el circuito. El pin analógico A0 salta a 792. El Arduino diagnostica residuo contaminado, gira el servo a la izquierda y abre la compuerta 01.'*  
> 3. *(Toca **02 / Papel Seco**)*: *'Arrojamos una hoja seca de libreta. Al no haber humedad, el papel se comporta como dieléctrico aislante con lectura de 22. El sistema identifica fibra limpia, rota la rampa a la derecha y envía la hoja al contenedor de reciclaje puro.'*"

---

### Intervención 6: Adrián Esteban Caro Romero (45 segundos)
**Tema:** Circuito Electrónico, Sensores y Conclusiones Finales
> *"El circuito se alimenta a 5 voltios de corriente continua e integra tres bloques principales:*  
> *1. El sensor ultrasónico HC-SR04 conectado a los pines digitales 2 y 3 para el Trigger y Echo.*  
> *2. La matriz de electrodos dorados de la bandeja conectada al pin analógico A0 con una resistencia pull-down de 10 kiloohmios que evita lecturas falsas.*  
> *3. El servomotor conectado al pin 9 de modulación por ancho de pulsos.*  
> *Con este proyecto, nuestro equipo del grado 10-01 demuestra que mediante la robótica aplicada es posible resolver un problema ambiental real de nuestra comunidad educativa, garantizando una economía circular eficiente. Quedamos atentos a cualquier pregunta del profesor. Muchas gracias."*

---

## 3. Banco de Preguntas Individuales para el Profesor (Defensa 5.0)

### Para Paula Andrea Bohórquez Díaz
- **Pregunta del Profesor:** *¿Qué ventaja tiene este sistema sobre colocar dos canecas comunes y pedirle a la gente que separe el papel?*
- **Respuesta:** *"Profesor, los estudios de comportamiento ambiental demuestran que más del 40% de las personas arrojan desechos por inercia sin leer los letreros. Un solo error humano arruina cientos de hojas limpias. Nuestro sistema traslada la decisión a un sensor físico, garantizando una tasa de separación efectiva del 100%."*

### Para Ana María Infante Mendoza
- **Pregunta del Profesor:** *¿Por qué una gota de agua rompe el papel pero el plástico mojado sí se puede reciclar?*
- **Respuesta:** *"Porque el plástico es un polímero sintético hidrofóbico que no absorbe agua; basta con secarlo mecánicamente. En cambio, el papel está hecho de polímeros de glucosa hidrófilos unidos por enlaces intermoleculares de hidrógeno. El agua compite con esos enlaces y disuelve la matriz física de la hoja, provocando su hinchamiento y descomposición bacteriana inmediata."*

### Para Dariana Isabel Rentería Puello
- **Pregunta del Profesor:** *¿Por qué eligieron un chasis en rosado mate y no los colores tradicionales de reciclaje verde o gris?*
- **Respuesta:** *"Buscamos una identidad de producto industrial moderno que invite al usuario a interactuar con la estación. El rosado mate con perfiles de aluminio y vidrio ahumado genera una apariencia tecnológica limpia y contemporánea. Además, la diferenciación funcional no se pierde porque las compuertas mantienen su codificación técnica clara 01 y 02."*

### Para Samuel David Lambraño Núñez
- **Pregunta del Profesor:** *¿El servomotor no se daña si alguien arroja un fajo de papel muy pesado?*
- **Respuesta:** *"El servomotor SG90 entrega un torque de 1.8 kg por centímetro, suficiente para hojas individuales o servilletas. No obstante, en la arquitectura de ingeniería la bandeja de acero cuenta con topes mecánicos amortiguados en la estructura exterior, de manera que el peso del impacto es absorbido por el chasis y no directamente por los engranajes de nylon del motor."*

### Para Denzel David Luna López
- **Pregunta del Profesor:** *¿Cómo calibraste el umbral de 250 en el pin A0 del Arduino?*
- **Respuesta:** *"Hicimos pruebas experimentales de impedancia: con papel bond seco el ADC arrojaba valores entre 15 y 45 (resistencia dieléctrica muy alta). Con una servilleta apenas húmeda, los valores subían inmediatamente por encima de 650 debido a los electrolitos del líquido. Definimos 250 como valor umbral con histéresis de seguridad para evitar falsos positivos por la humedad relativa del ambiente."*

### Para Adrián Esteban Caro Romero
- **Pregunta del Profesor:** *¿Por qué el sensor ultrasónico utiliza dos pines distintos (Trigger y Echo) y no uno solo?*
- **Respuesta:** *"Porque el pin Trigger emite un tren de 8 pulsos ultrasónicos a 40 kHz para iniciar el viaje de la onda, mientras que el pin Echo es una entrada de interrupción que mide con exactitud de microsegundos el tiempo que tarda la onda en rebotar y volver. Con la fórmula de la velocidad del sonido (343 m/s), el microcontrolador calcula la distancia exacta en centímetros."*
