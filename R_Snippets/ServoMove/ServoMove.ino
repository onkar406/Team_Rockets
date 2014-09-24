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
  if(a>=0 && a<=200)
  {
    int left,right;
    Serial.println("Checking Forward Distance...    ");
    Serial.print(a,DEC);

    Serial.println("");                                 

    int currentAngle = mServo.read();
    Serial.println(currentAngle,DEC);
    delay(500);

    mServo.write(179);
    delay(1000);
    Serial.println("Left Distance: ");
    Serial.print((left=getDistance()),DEC);
    Serial.println("");                                 

    delay(500);

    mServo.write(1);
    delay(1000);
    Serial.println("Right Distance: ");
    Serial.print((right=getDistance()),DEC);
    Serial.println("");                                 

    delay(500);

    if(left<right && (right-left)>=5) Serial.println("Turn right MAN!"); 
    else if(left>right && (left-right)>=5) Serial.println("Turn left MAN!");
    else Serial.println("Twist my neck and kill me! Please!!");

    mServo.write(currentAngle);            //Replace the currentAngle with 90
    delay(500);   
  }
  delay(1000);
}









