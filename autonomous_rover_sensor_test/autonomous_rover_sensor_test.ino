#define echo 8
#define trigger 7

float duration, cm;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  cm = (duration / 2.0) * 0.0343;
  delay(1);
  // Serial.print(millis()); 
  Serial.println(cm);
  delay(10);
}
