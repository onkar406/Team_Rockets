int INP_A1=4;
int INP_B1=10;
int INP_A2=5;
int INP_B2=11;
unsigned long distance = 0;
int reading;
void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}


void loop(){
  clk();
  delay(3000);
  free();
  delay(3000);
  anclk();
  delay(3000);
  brake();
  delay(3000);

  anclk();
  delay(3000);
  clk();
  delay(3000);

  free();
  delay(3000);
  clk();

  delay(8000);
  brake();
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






