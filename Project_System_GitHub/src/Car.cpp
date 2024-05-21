#include "Car.hpp"

#include <Arduino.h>

Car::Car(Button button, Buzzer buzzer, GyroScope gyroscope, Infrared infrared, Motor motor, SServo servo, UltraSound ultrasound) :
	button_{button},
	buzzer_{buzzer},
	gyroscope_{gyroscope},
	infrared_{infrared},
	motor_{motor},
	servo_{servo},
	ultrasound_{ultrasound}
{}

Button Car::getButton() const
{
	return button_;
}

Buzzer Car::getBuzzer() const
{
	return buzzer_;
}

GyroScope Car::getGyroScope() const
{
	return gyroscope_;
}

Infrared Car::getInfrared() const
{
	return infrared_;
}

Motor Car::getMotor() const
{
	return motor_;
}

SServo Car::getSServo() const
{
	return servo_;
}

UltraSound Car::getUltraSound() const
{
	return ultrasound_;
}
