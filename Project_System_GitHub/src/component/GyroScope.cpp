// TODO Fix and Organise this mess.
// https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/
#include "component/GyroScope.hpp"

#include <Arduino.h>
#include <Wire.h>

const int MPU_ADDR = 0x68;

GyroScope::GyroScope()
{
	// TODO Be more explicit with A4/A5 pins instead of hardcoding it.
	const int reg_6B = 0x6B;
	const int place_0_into_6B = 0x00;
	Wire.begin();
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(reg_6B);
	Wire.write(place_0_into_6B);
	Wire.endTransmission(true);
}

// TODO is a generator necessary?
void GyroScope::generate()
{
	const int reg_3B = 0x3B;
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(reg_3B);
	Wire.endTransmission(false);
	Wire.requestFrom(MPU_ADDR, 6, true);

	accelerometer_x_ = Wire.read() << 8 | Wire.read();
	accelerometer_y_ = Wire.read() << 8 | Wire.read();
	accelerometer_z_ = Wire.read() << 8 | Wire.read();
}

float GyroScope::angle_x()
{
}

float GyroScope::angle_y()
{
}

float GyroScope::angle_z()
{
}
