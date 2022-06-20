//EN1, EN2 with PWM ---> speed
//IN1, IN2, IN3, IN4 --> direction
//(in1, in3) ==> backward
//(in2, in4) ==> forward


//* all you need to do is change these values to correspond to your setup*//
#define en1 6
#define en2 5
#define in1 13
#define in2 12
#define in3 2
#define in4 3  

void setup() {
  // put your setup code here, to run once:
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

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //accelerate
  for(int i = 0; i <= 255; i++)
  {
    Serial.println(i);
    analogWrite(en1, i);
    analogWrite(en2, i);
    delay(100);
  }
  //deccelerate
  for(int i = 255; i >= 0; --i)
  {
    Serial.println(i);
    analogWrite(en1,i);
    analogWrite(en2,i);
    delay(100);
  }

}
