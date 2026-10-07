//! src/led.cpp

#include "led.h"

LED::LED(uint8_t pin) : _pinLed(pin)
{}

void LED::begin()
{
    pinMode(_pinLed, OUTPUT);
    digitalWrite(_pinLed, _stateLed);
    _previousActionTime_ms = millis();
}

void LED::update()
{
    if (_isBlinking)
    {
        const uint32_t elapsedTime = millis() - _previousActionTime_ms;

        if (elapsedTime >= _toggleWaitTime_ms)
        {
            _previousActionTime_ms = millis();
            toggle();
        }
    }

    digitalWrite(_pinLed, _stateLed);
}

void LED::turnOn()
{
    _stateLed = HIGH;
}

void LED::turnOff()
{
    _stateLed = LOW;
}

void LED::startBlinking(uint32_t waitTime_ms)
{
    _isBlinking = true;
    _toggleWaitTime_ms = waitTime_ms;
}

void LED::stopBlinking()
{
    _isBlinking = false;
    _stateLed = LOW;
}

void LED::toggle()
{
    _stateLed = !_stateLed;
}

uint8_t LED::getPinLed()
{
    return _pinLed;
}

bool LED::getStateLed()
{
    return _stateLed;
}

void LED::setStateLed(bool state)
{
    _stateLed = state;
}