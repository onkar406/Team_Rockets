#include<Servo.h>

Servo mServo;
class Movement
{
  int a1,a2,b1,b2;
public: 
  Movement(int a,int b,int c,int d)
  {
    b1 = a;
    a1 = b;
    b2 = c;
    a2 = d;

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
    digitalWrite(b2,HIGH);
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW); 
  }
  void goBackward()
  {
    digitalWrite(b1,LOW);
    digitalWrite(b2,LOW);
    digitalWrite(a1,HIGH);
    digitalWrite(a2,HIGH);
  }

};
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


Movement motor (3,5,6,10);
void setup()
{
  mServo.attach(9);
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  setPorts(7,8);  
}
void loop()
{
  motor.goForward();
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

    mServo.write(0);
    delay(1000);
    Serial.println("Right Distance: ");
    Serial.print((right=getDistance()),DEC);
    Serial.println("");                                 

    delay(500);

    if(left<right && (right-left)>=5) {
      Serial.println("Turn right MAN!"); 
      motor.turnRight();
      delay(1000);
      motor.reset();
    }

    else if(left>right && (left-right)>=5) 
    {
      Serial.println("Turn left MAN!");
      motor.turnLeft();
      delay(1000);

      motor.reset();
    }
    else 
    {
      Serial.println("Twist my neck and kill me! Please!!");
      motor.reset();
    }
    mServo.write(currentAngle);            //Replace the currentAngle with 90
    delay(500);   
  }
  Serial.println(getDistance());
  delay(1000);
}







