#define ledPin 12
#define sensorPin 4
#define wait 500
int sensorValue;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(sensorPin, INPUT);
    digitalWrite(sensorPin, HIGH);
}

void loop()
{
    sensorValue = digitalRead(sensorPin);

    if(sensorValue==1)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }

    delay(wait);
}