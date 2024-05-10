//
// Created by onno1 on 01/05/2024.
//

#include "gyro.h"
#include "math.h"
#include "Wire.h"
#include <Arduino.h>

const int GYROSCL = SCL;
const int GYROSDA = SDA;
///was not tested
int gyro::get_rise() {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
    Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
    Wire.requestFrom(MPU_ADDR, 7 * 2, true); // request a total of 7*2=14 registers

    int accelerometer_x = Wire.read() << 8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
    int accelerometer_y = Wire.read() << 8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
    int accelerometer_z = Wire.read() << 8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
    // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable

    double pitch = atan2(accelerometer_y, sqrt(pow(accelerometer_x, 2) + pow(accelerometer_z, 2))); // Calculation to get the pitch from the acceleration

    return pitch; // pitch is the variable that represents the angle, but the angle is not in degrees. keep in mind it oscillates
}

bool gyro::is_ramp() {
    int min_ramp=60;
    double pitch =get_rise();
    if(pitch>min_ramp){
        return true;
    }
    return false;
}

