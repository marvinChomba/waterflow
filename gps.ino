#include <SoftwareSerial.h> 
SoftwareSerial GpsSerial(12, 11); //RX,TX

void setup()
{   
  Serial.begin(115200);  //Debug Serial 
  GpsSerial.begin(9600);  //Gps Serial   
} 

void loop()
{ 
  if(GpsSerial.available() > 0)
  { 
    byte gpsData = GpsSerial.read(); 
//   Serial.write(gpsData); 
  } else {
//    Serial.println("Yooo");
  }
  delay(1000);
}
