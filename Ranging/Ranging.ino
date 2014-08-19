int echoPin = 6;  // digital pin to receive echo pulse
int triggerPin = 7;  // digital pin to send trigger pulse
unsigned long distance = 0;

void setup()
{  
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
}

void loop()
{
  digitalWrite(triggerPin, HIGH); // set HIGH for 15us to trigger ranging
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);  // set pin LOW
  distance = pulseIn(echoPin, HIGH);  // read in pulse length
  distance = distance / 58; // calculate distance from pulse length
  Serial.println(distance, DEC);
  delay(50);  // wait 50ms for next ranging
}

