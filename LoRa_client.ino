  #include <TimeLib.h>
#include <SPI.h>
#include <RH_RF95.h>
 
// Singleton instance of the radio driver
RH_RF95 rf95;

void setup() 
{ 
  Serial.begin(9600);
  setTime(11,52,0,31,10,22);
  while (!Serial) ; // Wait for serial port to be available
  if (!rf95.init())
    Serial.println("init failed from client");
  rf95.setSpreadingFactor(12);
  rf95.setCodingRate4(5);
  rf95.setTxPower(20, false);
  rf95.setSignalBandwidth(125000);
  Serial.println("Sending to rf95_server");

}
void loop()
{
  String radiopacket = String("35.12, ") + String("56.45, ") + String(hour()) + ":" + String(minute()) + ":" + String(second());
  rf95.send((uint8_t*)radiopacket.c_str(), radiopacket.length()+1);
  rf95.waitPacketSent();
  delay(5000);

}
 
