#include <TT_Turbidity.h>

#define tbdSensorPin 35

TT_Turbidity tbdSensor(tbdSensorPin);

float adcValue = 0.0;
unsigned long prevTime = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if ((millis() - prevTime) >= 1000)
    {
        adcValue = tbdSensor.getADC();
        Serial.print(F("ADC Reading Value => "));
        Serial.println(adcValue);
        prevTime = millis();
    }
}