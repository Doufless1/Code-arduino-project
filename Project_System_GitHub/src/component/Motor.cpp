#include "component/Motor.hpp"

#include <Arduino.h>

Motor::Motor(const int lpwm_pin, const int rpwm_pin) :
	lpwm_pin_{lpwm_pin},
	rpwm_pin_{rpwm_pin}
{
	pinMode(lpwm_pin_, OUTPUT);
	pinMode(rpwm_pin_, OUTPUT);
}

void Motor::move(int speed) const
{
	analogWrite(lpwm_pin_, (speed > 0) * speed);
	analogWrite(rpwm_pin_, (speed < 0) * -speed);
}

void Motor::stop() const
{
	analogWrite(lpwm_pin_, 0);
	analogWrite(rpwm_pin_, 0);
}
