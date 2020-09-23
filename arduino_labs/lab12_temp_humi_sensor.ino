#include <dht11.h>

#define dataPin 4

const int wait = 2000;

dht11 sensor;

void setup()
{
    // Start serial terminal
    Serial.begin(9600);
}

void loop()
{
    Serial.println();
    sensor.read11(dataPin);
    
    Serial.print("Humidity (%): ");
    Serial.println((float)sensor.humidity);
    
    Serial.print("Temperature (C): ");
    Serial.println((float)sensor.temperature);
    
    delay(wait);

}