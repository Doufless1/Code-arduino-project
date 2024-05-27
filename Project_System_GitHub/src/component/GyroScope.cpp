#include "component/GyroScope.hpp"

#include <Arduino.h>
#include <Wire.h>

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

const double GyroScope::angle() const
{
	const int reg_3B = 0x3B;
	const int reg_request = 7 * 2;
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(reg_3B);
	Wire.endTransmission(false);
	Wire.requestFrom(MPU_ADDR, reg_request, true);

	const int x = Wire.read() << 8 | Wire.read();
	const int y = Wire.read() << 8 | Wire.read();
	const int z = Wire.read() << 8 | Wire.read();

	// TODO Figure out a way to implement <math.h>, it doesn't seem to be supported on the arduino, or maybe I'm missing some libraries.
	const double angle = atan2(y, sqrt(pow(x, 2) + pow(z, 2)));
	return angle;
}
