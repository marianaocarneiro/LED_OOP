//! include/led.h

#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED
{
private:
    uint8_t _pinLed;
    bool _stateLed = 0;
    uint32_t _previousActionTime_ms = 0;
    bool _isBlinking = false;
    uint32_t _toggleWaitTime_ms = 0;

public:
    LED(uint8_t pin);

    void begin();
    void update();
    void turnOn();
    void turnOff();
    void startBlinking(uint32_t waitTime_ms = 500);
    void stopBlinking();
    void toggle();

    uint8_t getPinLed();
    bool getStateLed();
    void setStateLed(bool state);
};

#endif