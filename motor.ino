int in1 = 3;
int in2 = 1;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(100000000000000);
  digitalWrite(in1, LOW);
  delay(100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(100000000000000);
  digitalWrite(in2, LOW);
  delay(1000);
}
