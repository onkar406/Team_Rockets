class Movement
{
  int forward1,forward2,backward1,backward2;
  int enable1,enable2;
public: 
  Movement(int a,int b,int c,int d)
  {
    forward1 = a;
    backward1 = b;
    forward2 = c;
    backward2 = d;
    enable1 = true;
    enable2=true;
    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
  }
  void turnLeft(int s)
  {
    digitalWrite(forward1,HIGH);
    digitalWrite(backward1,HIGH);
    analogWrite(forward2,s);
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

Movement m(5,6,7,8);
void setup()
{
  digitalWrite(22,HIGH);
  digitalWrite(24,HIGH);  
}
void loop()
{
  m.goForward(100);
  delay(5000);
  m.goBackward(100);
  delay(5000);
  m.turnRight(100);
  delay(5000);
  m.turnLeft(100);
  delay(5000);
}

