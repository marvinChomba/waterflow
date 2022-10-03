   #include <FreqMeasure.h>

#define VCC2  5
 
int trigPin = 9;
int echoPin = 10;
long duration, cm, inches;

double sum=0;
int count=0;

int dst_out = 0;
float spd_out = 0;

unsigned long prevTime = millis();

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(VCC2,OUTPUT);//
  digitalWrite(VCC2, HIGH);//acts as 5V

  Serial.begin(57600);
  FreqMeasure.begin();
}

void distance() {
  
  digitalWrite(trigPin, LOW);
//  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2) / 29.1; 
  inches = (duration/2) / 74;

  if(cm <= 400) {
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  }
}

void velocity() {
    if (FreqMeasure.available()) {
      sum = sum + FreqMeasure.read();
      count = count + 1;
      if (count > 1) {
        float frequency = FreqMeasure.countToFrequency(sum / count);
        float spd = frequency  / 19.49; 
        String freqOutput = String(frequency, 3);
        String spdOutput = String(spd,3);
        Serial.println(spdOutput + "km/h");
        sum = 0;
        count = 0;
      }
    }
}


void loop() {
  unsigned long currentTime = millis();  
//  if((currentTime - prevTime) > 1000) {
//     distance();
//     prevTime = currentTime;
//  }
  velocity();
}
