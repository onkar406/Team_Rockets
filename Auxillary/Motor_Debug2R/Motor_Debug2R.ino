int INP_A1=3;
int EN_A=12;
int EN_B=13;


int INP_B1=5;
int INP_A2=6;
int INP_B2=10;
unsigned long distance = 0;
int reading;

  void clkA(){
    digitalWrite(INP_A1,HIGH);
    digitalWrite(INP_A2,LOW);
  }
  void clkB(){
    digitalWrite(INP_B1,HIGH);
    digitalWrite(INP_B2,LOW);
  }

  void anclkA(){
    digitalWrite(INP_A1,LOW);
    digitalWrite(INP_A2,HIGH);
  }
  void anclkB(){
    digitalWrite(INP_B1,LOW);
    digitalWrite(INP_B2,HIGH);

  }


  void brakeA(){
    digitalWrite(INP_A1,HIGH);
    digitalWrite(INP_A2,HIGH);
  }
  void brakeB(){
    digitalWrite(INP_B1,HIGH);
    digitalWrite(INP_B2,HIGH);
  }


  void free(){
    digitalWrite(EN_A,LOW);
    digitalWrite(EN_B,LOW);
  }


void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(EN_A, OUTPUT);
    pinMode(EN_B, OUTPUT);


}


void loop(){
  clkA();
  delay(3000);
  free();
  delay(3000);
  anclkA();
  delay(3000);
  brakeA();
  delay(3000);

  anclkB();
  delay(3000);
  clkB();
  delay(3000);

  free();
  delay(3000);
  clkA();

  delay(8000);
  brakeB();
  right();
  delay(3000);
  left();
  delay(3000);
  forw();
  delay(3000);
  back();
  delay(4000);
  brakeA();
  brakeB();
}
  void right(){
    clkA();
    anclkB();
  }

  void left(){
    clkB();
    anclkA();
  }

  void back(){
    clkA();
    clkB();
  }

  void forw(){
    anclkA();
    anclkB();
  }


/*Clockwise spin
 EN_A=HIGH  INP_A1= HIGH  INP_A2=LOW
 Anti-Clockwise spin
 EN_A=HIGH  INP_A1= LOW   INP_A2=HIGH
 Free Rotation
 EN_A=HIGH   INP_A1=LOW   INP_A3=LOW
 Brake
 EN_A=HIGH     INP_A1=HIGH   INP_A2=HIGH
 Free Rotation
 EN_A=LOW
 */






