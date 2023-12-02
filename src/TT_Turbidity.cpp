#include "TT_Turbidity.h"

/// @brief TT_Turbidity constructor
/// @param analog pin connected to Sensor as INPUT
TT_Turbidity::TT_Turbidity(uint8_t pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

/// @brief get ADC Value of sensor
/// @return float value
float TT_Turbidity::getADC()
{
    float readingADC = 0.0;
    for (int i = 0; i < SAMPLING_ADC; i++)
    {
        readingADC += analogRead(pin);
    }
    readingADC = readingADC / SAMPLING_ADC;
    return readingADC;
}

/// @brief get Voltage of sensor
/// @return float value
float TT_Turbidity::getVoltage()
{
    float readingVoltage = 0.0;
    for (int i = 0; i < SAMPLING_VOLTAGE; i++)
    {
        readingVoltage += ((float)analogRead(pin) / ADC_SCALE) * VREF;
    }
    readingVoltage = readingVoltage / SAMPLING_VOLTAGE;
    readingVoltage = roundToDp(readingVoltage, 1);
    return readingVoltage;
}

/// @brief get NTU Value of sensor
/// @return float value
float TT_Turbidity::getNTU()
{
    float readingVoltage = 0.0;
    float readingNTU = 0.0;
    for (int i = 0; i < SAMPLING_VOLTAGE; i++)
    {
        readingVoltage += ((float)analogRead(pin) / ADC_SCALE) * VREF;
    }
    readingVoltage = readingVoltage / SAMPLING_VOLTAGE;
    readingVoltage = roundToDp(readingVoltage, 1);
    if (readingVoltage < 2.5)
    {
        readingNTU = 3000;
    }
    else
    {
        readingNTU = -1120.4 * square(readingVoltage) + 5742.3 * readingVoltage - 4353.8;
    }
    return readingNTU;
}

/// @brief convert to decimal
/// @param value
/// @param decimal
/// @return float value
float roundToDp(float value, int decimal)
{
    float multiplier = powf(10.0f, decimal);
    value = roundf(value * multiplier) / multiplier;
    return value;
}