#include <TT_Turbidity.h>

#define tbdSensorPin 35

TT_Turbidity tbdSensor(tbdSensorPin);

float NTUValue = 0.0;
unsigned long prevTime = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if ((millis() - prevTime) >= 1000)
    {
        NTUValue = tbdSensor.getNTU();
        Serial.print(F("NTU Reading Value => "));
        Serial.println(NTUValue);
        prevTime = millis();
    }
}