//Bright or Dark?         by Onkar Anand	
//Parent code  (Original Sketch: sketch_mar07a.ino)		07 Mar 2013        11:37 am  
// Parent code for "Bright or Dark" Series

/*
This Program demonstrates the use of LDR.
 LDR is connected to Analog Pin A0. A voltage divider circuit is used to invert the values.
 V = 
 */
int ledPin = 9;
int ldrPin = A0;
int ldrVal = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  ldrVal= analogRead(ldrPin);
  Serial.println(ldrVal, DEC);
  if (ldrVal==0) digitalWrite(ledPin,LOW);
  else 
  {

    if (ldrVal>100) Serial.println("Its too bright out here");
    if (ldrVal<10) Serial.println("Its too dark....... I'm a little scared.... :( ");
    digitalWrite(ledPin, HIGH);
    delay(ldrVal);
    digitalWrite(ledPin,LOW);
    delay(ldrVal);
    ;
  }
}

/*   
 
 Vcc ----|
 |
 |
 |
 ___
 |LDR___|    <--R1 = LDR                
 |
 |
 |
 ____________ V(LDR InputPin)
 |
 |
 |
 |
 \
 /
 \
 /
 \     <--R2 =330ohm
 /
 \
 /
 | 
 |
 GND
 _____
 ---
 -    
 
 */

/*calibration
 Resistance =330 ohm
 vcc = 3.3v
 ldr as r1
 ldrval
 Direct/Plenty Sunlight -->  300 - 350
 diffused Light/ Ambient Light  --> 60 - 90
 */

