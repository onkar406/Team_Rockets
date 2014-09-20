// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
int echoPin = 6;  // digital pin to receive echo pulse
int triggerPin = 7;  // digital pin to send trigger pulse
int distance;

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

int pos = 0;    // variable to store the servo position 

void setup() 
{ 

  myservo.attach(9);
  Serial.begin(9600);  // attaches the servo on pin 9 to the servo object 
} 

int dis()
{
  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  delay(50);  // wait 50ms for next ranging  
  return distance;
}

void loop()   
{ 
  for(pos = 0; pos < 180; pos += 10)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
    dis();
    Serial.println(dis());    // waits 15ms for the servo to reach the position 


    Serial.println(myservo.read());    // waits 15ms for the servo to reach the position 
  } 

  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);  
    // waits 15ms for the servo to reach the position 

    Serial.println(myservo.read());  
  } 
} 





