float Inch=0.00;
int cm=0;
int SonarPin=A0;
int sensorValue;
int MIN_DIST=10;
int MAX_DIST=200;

/////////////////////////////////////////////////////
int AC_LOAD = 5;    // Output to Opto Triac pin
int dimming = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF
int MIN_LIGHT=95;
int MAX_LIGHT=35;

int A=MAX_LIGHT;   //todo
int B=MIN_LIGHT;  //nada
int C=5;
int DIMMER=0;


/////////////////////////////////////////////////////
void setup() 
{
  pinMode(SonarPin,INPUT);
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);  
  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////
void zero_crosss_int()  
// function to be fired at the zero crossing to dim the light
{
  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms  
  // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle) For 60Hz => 8.33ms

  // 10ms=10000us
  // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65
  int dimtime = (75*dimming);    // For 60Hz =>65     
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(10);         // triac On propogation delay
                                 //(for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}

///////////////////////////////////////////////////////////////
void loop() 
{
medicion();
if(cm>MIN_DIST && cm<MAX_DIST)
  {   
      delay(10);
      DIMMER=map(cm,MIN_DIST,MAX_DIST,MAX_LIGHT,MIN_LIGHT);            
     // Serial.print(cm);Serial.print(" - ");Serial.print(DIMMER);   
      RANGO_DIM(); 
     // Serial.print(" - ");Serial.println(dimming);
   }

}
///////////////////////////////////////////////////////////////////
void medicion()
{
sensorValue=analogRead(SonarPin);
delay(50);
Inch= (sensorValue*0.497);
cm=Inch*2.54;

}
///////////////////////////////////////////////////////////////////
void RANGO_DIM()
{
//  Serial.println("RANGO_DIM");    

  if(A<=DIMMER && DIMMER<A+C)
   {
    //for(int i=0; i <= 128; i++){
     dimming=A;
     delay(10);//}     
   } 
 else if(A+C<=DIMMER && DIMMER<A+2*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+C;
     delay(10);//}
    }
 else if(A+2*C<=DIMMER && DIMMER<A+3*C)
   {
  // for(int i=0; i <= 128; i++){
     dimming=A+2*C;
     delay(10);//}
   }
 else if(A+3*C<=DIMMER && DIMMER<A+4*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+3*C;
     delay(10);//}
   }
 else if(A+4*C<=DIMMER && DIMMER<A+5*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+4*C;
     delay(10);//}
   }
 else if(A+5*C<=DIMMER && DIMMER<A+6*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+5*C;
     delay(10);//}
   }
    else if(A+6*C<=DIMMER && DIMMER<A+7*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+6*C;
     delay(10);//}
   }
   else if(A+7*C<=DIMMER && DIMMER<A+8*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+7*C;
     delay(10);//}
   }
   else if(A+8*C<=DIMMER && DIMMER<A+9*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+8*C;
     delay(10);//}
   }
   else if(A+9*C<=DIMMER && DIMMER<A+10*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+9*C;
     delay(10);//}
   }
   else if(A+10*C<=DIMMER && DIMMER<A+11*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+10*C;
     delay(10);//}
   }
   else if(A+11*C<=DIMMER && DIMMER<A+12*C)
   {
   // for(int i=0; i <= 128; i++){
     dimming=A+11*C;
     delay(10);//}
   }
}
