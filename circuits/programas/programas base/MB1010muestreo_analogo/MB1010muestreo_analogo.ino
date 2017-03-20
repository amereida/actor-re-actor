float Inch=0.00;
float cm=0.00;
int SonarPin=A0;
int sensorValue;

void setup()
{
pinMode(SonarPin,INPUT);
Serial.begin(9600);
}
void loop()
{
sensorValue=analogRead(SonarPin);
delay(50);
Inch= (sensorValue*0.497);
cm=Inch*2.54;
Serial.print(cm);
Serial.println("cm");

}
