int var;

void setup() {  
  Serial.begin(9600);
  Serial.println("Starting"); 
  Serial.println("Enter Value"); 
}

void loop() {
  if (Serial.available() > 0) {
    var= Serial.read();

    switch (var) {
    case 1:


      Serial.println("Forward");
                            //do something when var equals 1
      break;
    case 2:

      Serial.println("Backward");

      //do something when var equals 2
      break;
    default: 

      delay(100);
      // if nothing else matches, do the default
      // default is optional




      // to eliminate unnecesary noise, serial monitor should have no line ending
    }
  }
}

