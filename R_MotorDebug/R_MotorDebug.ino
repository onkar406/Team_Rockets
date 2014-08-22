void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);  
}
void loop()
{
  debug(5,6,9,10,70);
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
/*void goBackward(int m21,int m22,int analogSpeed)
{
    for(int i=0;i<15;i++)
    {
      analogWrite(m21,LOW);
      digitalWrite(m22,analogSpeed);
      //delay(2);
    }
}
void goForward(int m11,int m12,int analogSpeed)
{
    for(int i=0;i<15;i++)
    {
      analogWrite(m11,analogSpeed);
      digitalWrite(m12,LOW);
      //delay(20);
    }
}*/
void debug(int m11,int m12,int m21,int m22,int analogSpeed) //Keep m11 high and m12 low for forward
{                                           //Keep m21 high and m22 low for forward
Serial.println("Both forward");
//Section for both forward
//goForward(m11,m12,analogSpeed);
//goForward(m21,m22,analogSpeed);
goAllForward(m11,m12,m21,m22,analogSpeed);
delay(300);
//Section for both backward
Serial.println("Both backward");
goAllBackward(m11,m12,m21,m22,analogSpeed);
//goBackward(m11,m12,analogSpeed);
//goBackward(m21,m22,analogSpeed);
delay(300);
//Section for left forward and right backward
/*Serial.println("One forward one backward");
goForward(m11,m12,analogSpeed);
goBackward(m21,m22,analogSpeed);
delay(300);
//Section for alternate
Serial.println("One forward, another one backward");
goBackward(m11,m12,analogSpeed);
goForward(m21,m22,analogSpeed);
delay(300);
*/
}