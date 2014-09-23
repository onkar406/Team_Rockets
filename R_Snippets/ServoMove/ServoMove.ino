#include<Servo.h>

Servo mServo;

int echo,trigger;
int setPorts(int ec,int tr)
{
  echo = ec;
  trigger = tr;
  pinMode(ec,INPUT);
  pinMode(tr,OUTPUT);
}
int getDistance()
{
  digitalWrite(trigger,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger,LOW);
  int a = pulseIn(echo,HIGH);
  a/=58;
  return a;
}
void setup()
{
  setPorts(6,7);  
  mServo.attach(9);
  Serial.begin(9600);
  mServo.write(90);
}
/*void loop()
 {
 mServo.write(180); 
 }*/
void loop()
{
  int a = getDistance();
  if(a<350)
  {
    int left,right;
    Serial.println("Checking...");
    Serial.println(a,DEC);
    int currentAngle = mServo.read();
    Serial.println(currentAngle,DEC);
    delay(500);
    mServo.write(179);
    Serial.println("Left: ");
    Serial.println((left=getDistance()),DEC);
    delay(1000);
    Serial.println("Right: ");
    mServo.write(1);
    Serial.println((right=getDistance()),DEC);
    delay(1000);
    if(left<=right) Serial.println("Go right man!"); 
    else if(left>=right) Serial.println("Go left MAN!");
    else Serial.println("Kill me now please!");
    mServo.write(currentAngle);
  }
  delay(1000);
}





