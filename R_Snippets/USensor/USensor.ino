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
  Serial.begin(9600);
}
void loop()
{
  Serial.println(getDistance(),DEC);
  delay(500);
}


