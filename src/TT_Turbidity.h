#ifndef TT_TURBIDITY_H
#define TT_TURBIDITY_H

#include <Arduino.h>

#define SAMPLING_ADC 100
#define SAMPLING_VOLTAGE 800

#if defined(AVR)
#define ADC_SCALE 1023.0f
#define VREF 5.0f
#elif defined(ESP8266)
#define ADC_SCALE 1023.0
#define VREF 3.3
#elif defined(ESP32)
#define ADC_SCALE 4095.0
#define VREF 3.3
#endif

class TT_Turbidity
{
public:
    TT_Turbidity(uint8_t pin);
    float getADC();
    float getVoltage();
    float getNTU();

private:
    uint8_t pin;
    float roundToDp(float value, int decimal);
};

#endif