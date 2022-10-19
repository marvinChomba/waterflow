#include <SPI.h>
#include <RH_RF95.h>
 
// Singleton instance of the radio driver
RH_RF95 rf95;


void setup() 
{
 
  Serial.begin(9600);
  while (!Serial) ; // Wait for serial port to be available
  if (!rf95.init())
    Serial.println("init failed from client");
 
  rf95.setSpreadingFactor(7);
  rf95.setCodingRate4(5);
  rf95.setTxPower(20, false);
  rf95.setSignalBandwidth(125000);
  Serial.println("Sending to rf95_server");

  
  // Send a message to rf95_server
  uint8_t data[]= "Hello, world";
  rf95.send(data, 2560);

//  Serial.print(sizeof(data));
  
  rf95.waitPacketSent();
}
 
void loop()
{

//  int i = 0;
//
//  while(i < 5) {
//
//  }
  
  // Now wait for a reply
  
//  uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
//  uint8_t len = sizeof(buf);
 
//  if (rf95.waitAvailableTimeout(3000))
//  { 
//    // Should be a reply message for us now   
//    if (rf95.recv(buf, &len))
//   {
//      Serial.print("got reply: ");
////      Serial.println((char*)buf);
////      Serial.print("RSSI: ");
////      Serial.println(rf95.lastRssi(), DEC);    
//    }
//    else
//    {
//      Serial.println("recv failed");
//    }
//  }
//  else
//  {
//    Serial.println("No reply, is rf95_server running?");
//  }
//  delay(400);
}
 
