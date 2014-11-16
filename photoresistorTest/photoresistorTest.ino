/*
Photoresistor
*/

// Photoresistor analog pin
const int sensorPin = 0;
// LED digital pin
const int ledPin = 9;
// threshold sensor value for on/off --- needs to be determined
const int threshold = 400;
// init variables
int lightLevel;

void setup()
{
  // create serial connection to use Serial Monitor
  Serial.begin(9600);
  // setup LED pin
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // read value from photoresistor
  lightLevel = analogRead(sensorPin);
  
  // prints value in Serial Monitor
  Serial.print("Photoresistor: ");
  Serial.println(lightLevel);
  
  if (lightLevel < threshold) {
    // if not dark, LED turns on
    analogWrite(ledPin, 255);
  } else {
    // if dark, LED turns off
    analogWrite(ledPin, 0);
  }
}

