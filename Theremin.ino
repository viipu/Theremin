/*
  - 64 ohm speaker + 47 ohm resistor on digital pin 9 
  - photoresistor on analog 0 to 5V
  - 4.7 kilohm resistor on analog 0 to ground
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0); // read sensor
  Serial.println(sensorReading); 
  // print sensor reading to check range
  // in this case seems to be 100-1000
  // map the analog input range to the output pitch range 
  // in this case let's choose 100 - 1500Hz
  // NB: map() allows values outside of range; so e.g. 90 ~> 84
  int thisPitch = map(sensorReading, 100, 1000, 100, 1500);
  
  tone(9, thisPitch, 10); // play the pitch:
  delay(1);        // delay for stability
}
