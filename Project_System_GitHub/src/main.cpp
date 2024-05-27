#include "Car.hpp"

#include <Arduino.h>
#include <Servo.h>

void setup()
{}

void loop()
{
	static Car car{
		Button(13),
		Buzzer(12),
		//GyroScope(),
		Infrared(13, 12, 11, 10, 9),
		Motor(6, 5),
		SServo(4),
		UltraSound(3, 2)
	};
	static bool running = true;

	if (car.is_button_pressed())
		running = !running;

	if (!running)
		return;

	if (car.is_all_on())
	{
		car.stop();
		car.look_straight();
		car.play_music();

		running = false;
		return;
	}

	if (car.is_middle_on())
		car.move(33);
	else
		car.move(28);

	if (car.is_any_on()/* && !car.is_middle_on()*/)
		car.change_angle(-11, 40);

	if (car.detects_obstacle(44, 46))
		car.evade_obstacle(35, 30, 630);

	delay(10);
}
