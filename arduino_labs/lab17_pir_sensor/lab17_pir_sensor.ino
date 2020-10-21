#define ledPin 13
#define pirPin 12

int pirStat=0;
 
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(pirPin, INPUT);     
}
 
void loop(){
  pirStat = digitalRead(pirPin); 
   
  if (pirStat == HIGH) 
  {
    digitalWrite(ledPin, HIGH);
  } 
  else 
  {
    digitalWrite(ledPin, LOW);
  }
}
