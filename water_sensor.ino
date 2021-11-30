const int capteur_D = 4;
const int capteur_A = A0;

int val_analogique;

void setup()
{
  pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val_analogique=analogRead(capteur_A); 
Serial.println(val_analogique);
if(val_analogique < 100) 
  {
    Serial.println("water level is correct"); 
    delay(10); 
  }
else
  {
    Serial.println("water level is dropped");
    delay(10); 
  }
val_analogique=analogRead(capteur_A); 
Serial.println(val_analogique);
  delay(1000);
}
