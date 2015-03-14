#include<Servo.h>
volatile int state = LOW;
#define rled A0
#define gled A1
Servo mServo;
class Movement
{
  int a1,a2,b1,b2;
public: 
  Movement(int a,int b,int c,int d)
  {
    b2 = a;
    a2 = b;
    b1 = c;
    a1 = d;

    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);

    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
  }
  void reset()
  {
    digitalWrite(b1,LOW);
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW);
    digitalWrite(b2,LOW);

  }
  void turnLeft()
  {
    digitalWrite(b1,HIGH);
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH);
    digitalWrite(b2,LOW);
  }
  void turnRight()
  {
    digitalWrite(a1,HIGH);
    digitalWrite(b1,LOW);
    digitalWrite(a2,LOW);
    digitalWrite(b2,HIGH);
  }
  void goForward()
  {
    digitalWrite(b1,HIGH);
    digitalWrite(b2,LOW);
    digitalWrite(a1,HIGH);
    digitalWrite(a2,LOW); 
  }
  void goBackward()
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,HIGH);
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH);
  }
};

void setup()
{
  analogWrite(gled,255);
  mServo.attach(9);
  mServo.write(90);
  pinMode(2,OUTPUT);
  setPorts(7,8); 
}

Movement motor(3,5,6,10);
void loop()
{
  int distance = getDistance();
  if(distance<100 && distance>=0) 
  {
    digitalWrite(2,HIGH);
    blink(distance);
  }
  motor.goForward();
  digitalWrite(2,LOW);
  delay(500);
}


int echo,trigger;
int setPorts(int ec,int tr)
{
  echo = ec;
  trigger = tr;
  pinMode(ec,INPUT);
  pinMode(tr,OUTPUT);

}
void blink(int fd)
{     
  motor.reset();
  analogWrite(rled,255);
  analogWrite(gled,0);
  int right,left;
  mServo.write(179);
  delay(500);
  right=getDistance();
  mServo.write(0);
  delay(500);
  left=getDistance();
  delay(500);                           
  mServo.write(90);
  if(left<right && (right-left)>=5) { 
    motor.turnRight();
    delay(750);
    motor.reset();
  }

  else if(left>right && (left-right)>=5) 
  {
    motor.turnLeft();
    delay(750);
    motor.reset();
  }
  else if((left-right)<5||(right-left)<5||fd<5)
  {
    motor.goBackward();
    delay(750);
  }
  else 
  {
    delay(500);
    return;   
  }
  delay(500); 
  analogWrite(rled,0);
  analogWrite(gled,255);
}

int getDistance()
{
  int sum=0;
  for(int i=0;i<25;i++)
  {
    digitalWrite(trigger,HIGH);
    delayMicroseconds(15);
    digitalWrite(trigger,LOW);
    int a = pulseIn(echo,HIGH);
    a/=58;
    sum+=a;
  }
  return sum/25;
}



