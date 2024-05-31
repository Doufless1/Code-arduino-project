#include "component/GyroScope.hpp"

#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include <MPU9250.h>
const int MPU_ADDR = 0x68;
MPU9250 gyro;
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
void GyroScope::SetupGyro() const{
    Wire.begin();
    if(!gyro.setup(0x68)){
        Serial.println("Failed to autodetect gyro type!");
        while(1);
    }
}

float GyroScope::The_Angle() const{

    gyro.update();

    float yDPS = (gyro.getGyroY() * 8.75) / 1000;// this is the raw valeus
    Serial.println(" Y: ");
    Serial.println(yDPS);
    float yRAD = yDPS  * (3.1459 / 180);
    Serial.println(" Y in RAD: ");
    Serial.println(yRAD);

    return yRAD;
}
