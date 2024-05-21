#include "Car.hpp"

#include <Arduino.h>

Car car{
	Button(13),
	Buzzer(12),
	GyroScope(),
	Infrared(11, 10, 9, 8, 7),
	Motor(6, 5),
	SServo(4), // TODO My servo does not work; make sure someone else tests it with their own.
	UltraSound(3, 2)
};

void setup()
{
	Serial.begin(9600);
}

void loop()
{

	static bool running = false;

	if (car.getButton().pressed())
		running = !running;

	if (!running)
		return;

	Serial.print(car.getInfrared().direction());
	Serial.print(" ");
	Serial.print(car.getUltraSound().distance());
	Serial.print(" ");

	car.getGyroScope().generate();
	Serial.print(car.getGyroScope().angle_x());
	Serial.print(" ");
	Serial.print(car.getGyroScope().angle_y());
	Serial.print(" ");
	Serial.print(car.getGyroScope().angle_z());
	Serial.println("");

	car.getBuzzer().play();
	running = false;
}
