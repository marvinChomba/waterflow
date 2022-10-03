#include <SPI.h>
#include <LoRa.h>


void setup() {
  Serial.begin(9600);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");
    while (LoRa.available()) {
      char incoming = (char)LoRa.read();
      if (incoming == 'c'){
        Serial.println("Dope");
      } else {
        Serial.println(incoming);
      } 
    }
  }
}
