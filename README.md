# Robot móvil diferencial con visión artificial para identificación de pelota objetivo

## Descripción del proyecto
Este proyecto corresponde a la materia de Visión Artificial y tiene como finalidad desarrollar un robot móvil con cámara, capaz de explorar su entorno hasta encontrar una pelota objetivo entre varias pelotas, en esta etapa se presenta el avance de la plataforma base, la integración preliminar de la cámara Pixy2 y una primera estrategia de reconocimiento visual.

## Objetivo
Diseñar e implementar un robot móvil diferencial que pueda capturar información visual del entorno, detectar una pelota específica y usar esa información como base para orientar su movimiento.

## Integrantes
Erick Maximiliano Ortiz Villareal, José Ángel Maldonado Villafaña, Josué Yael Hernández Rodríguez, Jonathan Leonel Maldonado Delgado, Gladis Lizbeth Alfaro Hinojosa, José Iván Guerrero Azua

## Tecnologías y herramientas usadas
Arduino UNO, Pixy2, Arduino IDE, PixyMon, modelado CAD, GitHub.

## Estructura del repositorio
```text
robot-vision-ball-search/
├── README.md
├── docs/
│   ├── reporte_avance.pdf
│   └── notas_de_prueba.md
├── src/
│   └── arduino/
│       └── pixy2_deteccion_preliminar/
│           └── pixy2_deteccion_preliminar.ino
├── media/
│   ├── fotos/
│   ├── capturas/
│   └── videos/
├── hardware/
│   ├── cad/
│   └── diagramas/
└── results/
    └── pruebas/
```

## Instrucciones básicas de ejecución
1. Instalar la librería oficial de Pixy2 en Arduino IDE.
2. Configurar la cámara con PixyMon y entrenar la firma visual de la pelota objetivo.
3. Abrir el archivo `src/arduino/pixy2_deteccion_preliminar/pixy2_deteccion_preliminar.ino`.
4. Compilar y cargar el programa en Arduino UNO.
5. Abrir el monitor serial para verificar la detección de la pelota.

## Evidencia del avance
En este repositorio se recomienda colocar fotografías del prototipo, capturas del reconocimiento de la cámara, videos de movilidad y archivos del diseño mecánico, para que el avance quede documentado de forma clara y ordenada.

## Estado actual
Se cuenta con el diseño base del carro diferencial, la integración preliminar de la cámara y pruebas iniciales de reconocimiento de la pelota objetivo.
