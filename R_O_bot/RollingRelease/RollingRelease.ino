#include<Servo.h>

Servo mServo;
class Movement
{
  int forward1,forward2,backward1,backward2;
public: 
  Movement(int a,int b,int c,int d)
  {
    forward1 = a;
    backward1 = b;
    forward2 = c;
    backward2 = d;

    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
  }
  void turnLeft(int s)
  {
    digitalWrite(forward1,HIGH);
    digitalWrite(backward1,HIGH);
    analogWrite(forward2,LOW);
    digitalWrite(backward2,LOW);
  }
  void turnRight(int s)
  {
    digitalWrite(forward2,HIGH);
    digitalWrite(backward2,HIGH);
    analogWrite(forward1,s);
    digitalWrite(backward1,LOW);
  }
  void goForward(int s)
  {
    analogWrite(forward1,s);
    analogWrite(forward2,s);
    digitalWrite(backward1,LOW);
    digitalWrite(backward2,LOW); 
  }
  void goBackward(int s)
  {
    digitalWrite(forward1,LOW);
    digitalWrite(forward2,LOW);
    analogWrite(backward1,s);
    analogWrite(backward1,s);
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
  digitalWrite(trigger,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigger,LOW);
  int a = pulseIn(echo,HIGH);
  a/=58;
  return a;
}
Movement motor(10,11,12,13);
void setup()
{
  mServo.attach(9);
  Serial.begin(9600);
<<<<<<< HEAD
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  setPorts(7,8);  
=======
  //digitalWrite(22,true);
  //digitalWrite(24,true);
  setPorts(6,7);  
>>>>>>> origin/master
}
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
    //Serial.println(currentAngle,DEC);
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

    if(left<right && (right-left)>=5) {Serial.println("Turn right MAN!");motor.turnLeft(150);delay(3000);motor.goForward(150); }
    else if(left>right && (left-right)>=5) {Serial.println("Turn left MAN!");motor.turnRight(150);delay(3000);motor.goForward(150);}
    else Serial.println("Twist my neck and kill me! Please!!");

    mServo.write(currentAngle);            //Replace the currentAngle with 90
    delay(500);   
  }
  Serial.println(getDistance());
  delay(1000);
}
