#include<Servo.h>

int echoPin = 6;  // digital pin to receive echo pulse
int triggerPin = 7;  // digital pin to send trigger pulse
unsigned long distance = 0;
Servo myServo;
int pos=0;
void setup()
{  
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
}

void loop()
{
  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  Serial.println(distance, DEC);
  delay(50);  // wait 50ms for next ranging

  if(distance<40)
  {
    Serial.println("Left");
    myServo.write(60);
    delay(50);

  }
  else if(distance>40)
  {
    Serial.println("Right");
    myServo.write(120);
    delay(50);

  }
  delay(2000);
  pos=0;


}




