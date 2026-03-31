#include <SPI.h>
#include <Pixy2.h>

Pixy2 pixy;

// -------- Pixy2 --------
const uint8_t FIRMA_OBJETIVO = 1;
const uint32_t AREA_MINIMA = 100;   // ajusta este valor según tu prueba

// -------- IBT-2 --------
const int RPWM = 5;
const int LPWM = 6;
const int REN  = 7;
const int LEN  = 8;

const int VELOCIDAD_ADELANTE = 180;
const int VELOCIDAD_ATRAS    = 180;

void detenerMotores() {
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void avanzar() {
  analogWrite(RPWM, VELOCIDAD_ADELANTE);
  analogWrite(LPWM, 0);
}

void retroceder() {
  analogWrite(RPWM, 0);
  analogWrite(LPWM, VELOCIDAD_ATRAS);
}

void setup() {
  Serial.begin(115200);

  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(REN, OUTPUT);
  pinMode(LEN, OUTPUT);

  digitalWrite(REN, HIGH);
  digitalWrite(LEN, HIGH);

  detenerMotores();

  Serial.println("Iniciando Pixy2...");
  pixy.init();
  Serial.println("Sistema listo");
}

void loop() {
  int8_t bloques = pixy.ccc.getBlocks();

  if (bloques < 0) {
    Serial.println("Error de comunicacion con Pixy2");
    detenerMotores();
    delay(100);
    return;
  }

  if (bloques == 0) {
    Serial.println("No detectada");
    detenerMotores();
    delay(40);
    return;
  }

  // Busca el bloque mas grande de la signature 1
  int mejorIndice = -1;
  uint32_t mejorArea = 0;

  for (uint8_t i = 0; i < pixy.ccc.numBlocks; i++) {
    if (pixy.ccc.blocks[i].m_signature == FIRMA_OBJETIVO) {
      uint32_t area = (uint32_t)pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;

      if (area > mejorArea) {
        mejorArea = area;
        mejorIndice = i;
      }
    }
  }

  if (mejorIndice >= 0 && mejorArea >= AREA_MINIMA) {
    uint16_t x = pixy.ccc.blocks[mejorIndice].m_x;
    uint16_t y = pixy.ccc.blocks[mejorIndice].m_y;
    uint16_t w = pixy.ccc.blocks[mejorIndice].m_width;
    uint16_t h = pixy.ccc.blocks[mejorIndice].m_height;

    Serial.print("PELOTA DETECTADA | X=");
    Serial.print(x);
    Serial.print(" Y=");
    Serial.print(y);
    Serial.print(" W=");
    Serial.print(w);
    Serial.print(" H=");
    Serial.print(h);
    Serial.print(" AREA=");
    Serial.println(mejorArea);

    avanzar();
  } else {
    Serial.println("Signature 1 no valida o muy pequena");
    detenerMotores();
  }

  delay(30);
}