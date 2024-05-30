#include "component/GyroScope.hpp"

#include <Arduino.h>
#include <Wire.h>
#include <math.h>

const int MPU_ADDR = 0x68;

GyroScope::GyroScope(const int A4, const int A5)
{
	(void) A4;
	(void) A5;

	const int reg_6B = 0x6B;
	const int place_0_into_6B = 0x00;
	Wire.begin();
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(reg_6B);
	Wire.write(place_0_into_6B);
	Wire.endTransmission(true);
}

double GyroScope::pitch() const
{
	/*const int reg_43 = 0x43;
	const int reg_request = 6;
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(reg_43);
	Wire.endTransmission(false);
	Wire.requestFrom(MPU_ADDR, reg_request, true);

	int current_time = millis();
	static int previous_time = current_time;
	int elapsed_time = current_time - previous_time;

	static int x_previous = 0;
	static int y_previous = 0;
	static int z_previous = 0;

	int x_gyroscope = Wire.read() << 8 | Wire.read();
	int y_gyroscope = Wire.read() << 8 | Wire.read();
	int z_gyroscope = Wire.read() << 8 | Wire.read();

	x_previous = ;
	y_previous = y_previous + y_gyroscope * elapsed_time;
	z_previous = z_previous + z_gyroscope * elapsed_time;

	previous_time = current_time;

	static double yaw = yaw + z_gyroscope * elapsed_time;
	double roll = (x_previous + x_gyroscope * elapsed_time) * 0.96 +;
	double pitch = ;
	return pitch;*/
	return 0;
}
