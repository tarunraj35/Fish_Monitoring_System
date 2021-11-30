
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0);
  // print out the value you read:
  if(sensorValue<500)
  {
    Serial.println("water is cloudy");
    } 
    if(sensorValue>600)
    {
      Serial.println("water is clear");
      }
      if(sensorValue<=300)
      {
        Serial.println("water is dirty");
        }
  delay(100);
  // delay in between reads for stability
}
