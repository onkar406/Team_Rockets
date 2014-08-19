//ASCII Table	Parent code  (Original Sketch: sketch_may22b.ino)		22 May 2013        03:15 pm  
// Parent code for "ASCII Table" Series

/*
This Program demonstrates the conversion of any character into its ASCII value.
No hardware required except Arduino.
Tested on Arduino Uno
*/


int incomingByte = 0;
void setup() {
        Serial.begin(9600);
        Serial.println("ASCII Table ~ Character Map");
        Serial.println("Enter a Value");
}

void loop() {

        if (Serial.available() > 0) 
        {
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.print(incomingByte, DEC);
                Serial.print(", hex: "); 
                Serial.print(incomingByte, HEX);
                Serial.print(", oct: ");
                Serial.print(incomingByte, OCT);
                Serial.print(", bin: "); 
                Serial.println(incomingByte, BIN);
                Serial.println("Enter a Value");
        }
}

