#include <SPI.h>
  #include <TimeLib.h>
#include <RH_RF95.h>
 
// Singleton instance of the radio driver
RH_RF95 rf95;

 
void setup() 
{
 
//  pinMode(led, OUTPUT);     
  Serial.begin(9600);
  setTime(13,45,0,31,10,22);
  while (!Serial) ; // Wait for serial port to be available
  if (!rf95.init()) {
        Serial.println("init failed from server");  

  } else {
    Serial.println("Connected");
  }
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
 rf95.setSpreadingFactor(12);
 rf95.setCodingRate4(5);
 rf95.setTxPower(20, false);
 rf95.setSignalBandwidth(125000);
}
 
void loop()
{
  if (rf95.available())
  {
    // Should be a message for us now   
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len))
    {
//      RH_RF95::printBuffer("request: ", buf, len);
//      Serial.print("got request: ");
      Serial.println((char*)buf);
      String time_now = String(hour()) + ":" + String(minute()) + ":" + String(second());
      Serial.println(time_now);
      Serial.print("RSSI: ");
      Serial.println(rf95.lastRssi(), DEC);
      
    }
    else
    {
      Serial.println("recv failed");
    }
  }
}
 
