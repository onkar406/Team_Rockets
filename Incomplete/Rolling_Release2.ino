#include <Servo.h>

Servo myservo;
int disL;
int disR;
int pos = 90;
int EN_A=3;      //Enable Motor A
int EN_B=12;      //Enable Motor B
int INP_A1=4;
int INP_B1=10;
int INP_A2=5;
int INP_B2=11;
int echoPin = 6;  // digital pin to receive echo pulse
int triggerPin = 7;  // digital pin to send trigger pulse
unsigned long distance = 0;
int reading;
void setup()
{

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
}


void loop(){



  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  delay(50);  // wait 50ms for next ranging




  if (distance<10) 
  {
    myservo.write(45);
    digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
    delayMicroseconds(15);
    digitalWrite(triggerPin, LOW);  // set pin LOW
    disL = pulseIn(echoPin, HIGH);  // read in pulse length
    disL = disL / 58; // calculate distance from pulse length
    delay(5);

     myservo.write(150);
    digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
    delayMicroseconds(15);
    digitalWrite(triggerPin, LOW);  // set pin LOW
    disL = pulseIn(echoPin, HIGH);  // read in pulse length
    disR = disR / 58; // calculate distance from pulse length
    delay(5);

      if (disL>disR){ 
        left;
      }
      else if(disL<disR){
        right;
      }
      else back;
    delay(20);
  }

  else {
    forw;
  } 
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



void clkA(){
  digitalWrite(EN_A,HIGH);
  digitalWrite(INP_A1,HIGH);
  digitalWrite(INP_A2,LOW);
}
void clkB(){
  digitalWrite(EN_B,HIGH);
  digitalWrite(INP_B1,HIGH);
  digitalWrite(INP_B2,LOW);
}

void anclkA(){
  digitalWrite(EN_A,HIGH);
  digitalWrite(EN_A,HIGH);
  digitalWrite(INP_A1,LOW);
  digitalWrite(INP_A2,HIGH);
}
void anclkB(){
  digitalWrite(EN_B,HIGH);
  digitalWrite(INP_B1,LOW);
  digitalWrite(INP_B2,HIGH);

}


void brakeA(){
  digitalWrite(EN_A,HIGH);
  digitalWrite(INP_A1,HIGH);
  digitalWrite(INP_A2,HIGH);
}
void brakeB(){
  digitalWrite(EN_B,HIGH);
  digitalWrite(INP_B1,HIGH);
  digitalWrite(INP_B2,HIGH);
}


void free(){
  digitalWrite(EN_A,LOW);
  digitalWrite(EN_B,LOW);
}



int servoL(int distanceL){
  myservo.write(0);
  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  delay(20);
  return distance;
}

int servoR(int distanceR){
  myservo.write(180);
  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  delay(20);
  return distance;
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








