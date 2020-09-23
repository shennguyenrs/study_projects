#define trigPin 12
#define echoPin 11
#define wait 100
#define sendingTime 10
#define delaySending 2

const float sonicVelocity = 0.034; // cm per microsecond

void setup()
{
    Serial.begin(9600); // Start serial terminal
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    int duration
    float distance;

    // Clear trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(delaySending);
    
    // Start to send ultrasonic
    digitalWrite(trigPin, HIGH);
    delaySending(sendingTime);
    digitalWrite(trigPin, LOW);

    // Read echoPin, return duration time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance in cm
    distance = duration*sonicVelocity/2;
    
    // Print out in serial
    Serial.print(distance);
    Serial.print(" cm");
    Serial.println();

    delay(wait)
}
