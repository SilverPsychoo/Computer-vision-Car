#include <SPI.h>
#include <Pixy2.h>

Pixy2 pixy;

const uint8_t FIRMA_OBJETIVO = 1;
const uint32_t AREA_MINIMA = 150;

// L298N
const int ENA = 5;
const int IN1 = 7;
const int IN2 = 8;
const int ENB = 6;
const int IN3 = 9;
const int IN4 = 10;

const int VELOCIDAD = 140;

void detenerMotores() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void avanzar() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, VELOCIDAD);
  analogWrite(ENB, VELOCIDAD);
}

void setup() {
  Serial.begin(115200);
  pixy.init();

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  detenerMotores();
  Serial.println("Prueba preliminar carrito + Pixy2");
}

void loop() {
  int8_t bloques = pixy.ccc.getBlocks(false, 1, 1);

  if (bloques > 0) {
    uint16_t w = pixy.ccc.blocks[0].m_width;
    uint16_t h = pixy.ccc.blocks[0].m_height;
    uint32_t area = (uint32_t)w * h;

    if (pixy.ccc.blocks[0].m_signature == FIRMA_OBJETIVO && area >= AREA_MINIMA) {
      avanzar();
      Serial.println("Veo la pelota -> AVANZAR");
    } else {
      detenerMotores();
      Serial.println("Bloque insuficiente -> DETENER");
    }
  } else {
    detenerMotores();
    Serial.println("No veo pelota -> DETENER");
  }

  delay(40);
}