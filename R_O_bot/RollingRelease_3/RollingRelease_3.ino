#include<Servo.h>

Servo mServo;
int left,right;
int led=12;           //attach an LED to pin 12

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

void blinklow()
{
  for(int i=0;i<5;i++) 
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }
}

void blinkhigh()
{
  for(int i=0;i<5;i++) 
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(300);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(300);
  }
}

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
  int sum=0;
  for(int i=0;i<15;i++)
  {
    digitalWrite(trigger,HIGH);
    delayMicroseconds(15);
    digitalWrite(trigger,LOW);
    int a = pulseIn(echo,HIGH);
    a/=58;
    sum+=a;
  }
  return sum/15;
}


Movement motor (3,5,6,10);
void setup()
{
  mServo.attach(9);
  pinMode(led,OUTPUT);
  setPorts(7,8);  

}
void loop()
{								//create a function to check distance
								//invoke the function at begining

  motor.goForward();
  delay(100);
  blinklow();
  int a = getDistance();
  if(a>=0 && a<=200)
  {
    mServo.write(179);
    delay(500);
    right=getDistance();
    blinkhigh();

    mServo.write(0);
    delay(500);
    left=getDistance();
    blinkhigh();

    delay(500);                           
  }

  if(left<right && (right-left)>=5) { 
    motor.turnRight();
    delay(1000);
    motor.reset();
  }

  else if(left>right && (left-right)>=5) 
  {
    motor.turnLeft();
    delay(1000);

    motor.reset();
  }
  else 
  {
    motor.reset();
    mServo.write(90);            //Replace the currentAngle with 90
    delay(500);   
  }
  delay(1000);
}


