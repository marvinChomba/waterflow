#include <LoRa.h>

#include <SPI.h>

unsigned long startTime = millis();
int RXPin = 3;
int TXPin = 4;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();  
  if(currentTime-startTime > 2000) {
    LoRa.beginPacket();
    LoRa.print("Lat: ");
    LoRa.println(0.12121212, 6);
    LoRa.print("c");
    LoRa.print("Long: ");
    LoRa.println(0.12121212, 6);
    Serial.println("Sent via LoRa");
    LoRa.endPacket();
    startTime = currentTime;
  }
  
}
