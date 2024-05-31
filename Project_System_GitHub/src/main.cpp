//#include "Car.hpp"

#include <Arduino.h>
//#include <Servo.h>

#include <Wire.h>
#include <MPU9250.h>

MPU9250 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize communication with the MPU-9250, and confirm it's connected
  if (!mpu.setup(0x68)) {  // Change to 0x69 if needed
    while (1) {
      Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
      delay(5000);
    }
  }
}

void loop() {
  // Update the sensor data
  if (mpu.update()) {
    // Gyroscope values in degrees per second
    Serial.print("Gyroscope X: ");
    Serial.print(mpu.getGyroX());
    Serial.print(" dps\t");
    Serial.print("Gyroscope Y: ");
    Serial.print(mpu.getGyroY());
    Serial.print(" dps\t");
    Serial.print("Gyroscope Z: ");
    Serial.print(mpu.getGyroZ());
    Serial.println(" dps");
  }

  delay(100);  // Update at 10 Hz
}
/*
void setup()
{}

void loop()
{
	static Car car{
		Button(4),
		Buzzer(8),
		GyroScope(A4, A5),
		Infrared(9, 10, 11, 12 , 13),
		Motor(6, 5),
		SServo(7),
		UltraSound(3, 2)
	};
	static bool running = false;

	if (car.is_button_pressed())
		running = !running;

	if (!running)
	{
		car.stop();
		car.look_straight();
		delay(10);
		return;
	}

	if (car.is_all_on())
	{
		car.stop();
		car.look_straight();
		car.play_music();

		running = false;
		return;
	}

	if (car.is_only_middle_on())
		car.move(33);
	else
		car.move(28);

	if (car.is_only_middle_on())
		car.look_straight();
	else if (car.is_any_on())
		car.change_angle(11, 30);

	if (car.detects_obstacle(45, 50))
		car.evade_obstacle(40, 30, 750);

	delay(10);
}*/
