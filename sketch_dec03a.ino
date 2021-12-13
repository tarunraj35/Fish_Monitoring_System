
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  int sensorValue = analogRead(A0);
  String water_status="";
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  //Serial.print(" C  ");
  //Serial.print(Celcius);
  /*Serial.print(" F  ");
  Serial.println(Fahrenheit);*/
  // print out the value you read:
  if(sensorValue>=300)
  {
    water_status="water is clear";
  } 
  if(sensorValue<300 && sensorValue>=201)
  {
      water_status="water is cloudy";
  }
  if(sensorValue<=200)
  {
      water_status="water is dirty";
  }
  
  Serial.print("{\"Temperature\":");
  Serial.print(Celcius);
  Serial.print(",\"Turbidity\":");
  Serial.print(sensorValue);
  Serial.println("}");
  delay(1000);
}
