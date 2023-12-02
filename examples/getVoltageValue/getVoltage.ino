#include <TT_Turbidity.h>

#define tbdSensorPin 35

TT_Turbidity tbdSensor(tbdSensorPin);

float voltageValue = 0.0;
unsigned long prevTime = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if ((millis() - prevTime) >= 1000)
    {
        voltageValue = tbdSensor.getVoltage();
        Serial.print(F("Voltage Reading Value => "));
        Serial.println(voltageValue);
        prevTime = millis();
    }
}