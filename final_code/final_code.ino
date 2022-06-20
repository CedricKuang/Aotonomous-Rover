#define en1 6
#define en2 5
#define in1 13
#define in2 12
#define in3 2
#define in4 3  
#define echo 8
#define trigger 7

float duration, curr_cm, prev_cm, delta;
int car_speed;
int gain = 7;


void setup() {
  // initialize sensor
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  // initialize controller
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);

  //sets motors to move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);

  prev_cm = 10.0;
  delta = 0;
  car_speed = 50;
}

void loop() {
  // collect data;
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  curr_cm = (duration / 2.0) * 0.0343;
  delay(10);

  delta = curr_cm - prev_cm;
  if (curr_cm > 10.0)      // distance larger than threshold, go forward
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    car_speed += (delta * gain);
  }
  else if (curr_cm < 10.0)    // distance smaller than threshold, go backward
  {
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
    car_speed -= (delta * gain);
  }
  if (car_speed > 255)
    car_speed = 255;
  else if (car_speed < 0)
    car_speed = 0;

  analogWrite(en1, car_speed);
  analogWrite(en2, car_speed);
  delay(100);

  prev_cm = curr_cm;
}
