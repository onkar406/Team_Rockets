/*
  Motor Debugging Program
 By Human(Ashish Mehrotra)
 */

void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);  
}
void loop()
{
  debug(5,6,7,8,70);
}
void goAllBackward(int m11,int m12,int m21,int m22,int analogSpeed)
{
  for(int i=0;i<15;i++)
  {
    analogWrite(m21,LOW);
    digitalWrite(m22,analogSpeed);
    analogWrite(m11,LOW);
    digitalWrite(m12,analogSpeed);
    delay(200);
  }
}
void goAllForward(int m11,int m12,int m21,int m22,int analogSpeed)
{
  for(int i=0;i<15;i++)
  {
    analogWrite(m21,analogSpeed);
    digitalWrite(m22,LOW);
    analogWrite(m11,analogSpeed);
    digitalWrite(m12,LOW);
    delay(200);
  }
}
//-------------------------FUNCTIONS FOR WHEEL MOVEMENT IN ALTERNATE DIRECTIONS------------------------------
void goAlternate1(int m11,int m12,int m21,int m22,int analogSpeed)
{
  for(int i=0;i<15;i++)
  {
    analogWrite(m21,LOW);
    digitalWrite(m22,analogSpeed);
    analogWrite(m11,analogSpeed);
    digitalWrite(m12,LOW);
    delay(200);
  } 
}
void goAlternate2(int m11,int m12,int m21,int m22,int analogSpeed)
{
  for(int i=0;i<15;i++)
  {
    analogWrite(m11,LOW);
    digitalWrite(m12,analogSpeed);
    analogWrite(m21,analogSpeed);
    digitalWrite(m22,LOW);
    delay(200);
  } 
}
//----------------------------------------------------------------------------------------------------------
void debug(int m11,int m12,int m21,int m22,int analogSpeed) //Keep m11 high and m12 low for forward
{                                           //Keep m21 high and m22 low for forward
  Serial.println("Both forward");
  goAllForward(m11,m12,m21,m22,analogSpeed);
  delay(300);
  Serial.println("Both backward");
  goAllBackward(m11,m12,m21,m22,analogSpeed);
  delay(300);
  goAlternate1(m11,m12,m21,m22,analogSpeed);
  delay(300);
  goAlternate2(m11,m12,m21,m22,analogSpeed);
  delay(300);
}

