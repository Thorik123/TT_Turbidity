#include <TT_Turbidity.h>

#define tbdSensorPin 35

TT_Turbidity tbdSensor(tbdSensorPin);

float adcValue = 0.0;
float voltageValue = 0.0;
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
        adcValue = tbdSensor.getADC();
        Serial.print(F("ADC Reading Value => "));
        Serial.println(NTUValue);

        voltageValue = tbdSensor.getVoltage();
        Serial.print(F("Voltage Reading Value => "));
        Serial.println(voltageValue);

        NTUValue = tbdSensor.getNTU();
        Serial.print(F("NTU Reading Value => "));
        Serial.println(NTUValue);
        prevTime = millis();
    }
}