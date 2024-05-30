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
{
	servo_.init();
}

bool Car::is_button_pressed() const
{
	return button_.pressed();
}

void Car::play_music() const
{
	const int G3 = 196;
	const int A3 = 220;
	const int B3 = 247;
	const int C4 = 262;

	struct
	{
		int note;
		int duration;
	} melody[] =
	{
		{C4, 4},
		{G3, 8},
		{G3, 8},
		{A3, 4},
		{G3, 4},
		{0 , 4},
		{B3, 4},
		{C4, 4}
	};
	const int len = sizeof(melody) / sizeof(melody[0]);
	for (int i = 0; i < len; i++)
		buzzer_.play(melody[i].note, melody[i].duration);
}

// TODO GyroScope

int Car::is_only_middle_on() const
{
	return infrared_.direction() == 0b00100;
}

bool Car::is_all_on() const
{
	return infrared_.direction() == 0b11111;
}

bool Car::is_any_on() const
{
	return infrared_.direction() != 0;
}

const int Car::change_angle(const int slight, const int far) const
{
	const int direction = infrared_.direction();
	const int slight_angle = !!(direction & 0b01000) * (-slight) + !!(direction & 0b00010) * slight;
	const int far_angle = !!(direction & 0b10000) * (-far) + !!(direction & 0b00001) * far;

	const int angle = (far_angle + slight_angle) / ((slight_angle != 0 && far_angle != 0) ? 2 : 1);
	servo_.angle(angle);
}

void Car::move(const int speed) const
{
	motor_.move(speed);
}

void Car::stop() const
{
	motor_.move(0);
}

void Car::look_straight() const
{
	servo_.angle(0);
}

bool Car::detects_obstacle(const int closest, const int furthest) const
{
	const int distance = ultrasound_.distance();
	return distance >= closest && distance <= furthest;
}

void Car::evade_obstacle(const int speed, const int angle, const int time) const
{
	motor_.move(speed);

	servo_.angle(-angle);
	delay(time);

	servo_.angle(angle);
	delay(time);
}
