/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 9;
int inPin = 10;
int reading;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode (inPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value==0x6F948B7){
      reading = digitalRead(inPin);
      Serial.println(reading);
      reading = !reading;
    }
    digitalWrite(inPin, reading);
    if(results.value!=0xFFFFFFFF) ;
    {
      if(results.value==0x6F9807F) analogWrite(inPin, 64);
      if(results.value==0x6F940BF) analogWrite(inPin, 127);
      if(results.value==0x6F9C03F) analogWrite(inPin, 191);
      if(results.value==0x6F920DF) analogWrite(inPin, 225);
      if(results.value =0x6F918E7) { 
        for (int i=0; i<=100; i++)
        {
          digitalWrite(inPin, HIGH);   // set the LED on
          delay(100);              // wait for a second
          digitalWrite(inPin, LOW);    // set the LED off
          delay(100);
          i=i++;    // wait for a second
        }
      }
    }
    delay(40);
    irrecv.resume(); // Receive the next value
  }
}




/*
include <IRremote.h>
 
 int RECV_PIN = 11;
 
 IRrecv irrecv(RECV_PIN);
 
 decode_results results;
 
 void setup() {
 Serial.begin(9600);           // Set up serial communication at 9600bps
 irrecv.enableIRIn(); // Start the receiver
 pinMode(12, OUTPUT);
 }
 
 void loop(){
 if (irrecv.decode(&results)) {
 Serial.print(results.value, HEX);
 Serial.print('\t');
 Serial.println(results.value, DEC);
 if (results.value==0x5D0)
 { 
 digitalWrite(12, HIGH);
 digitalRead(12);
 }
 irrecv.resume(); // Receive the next value
 }
 }
 */



