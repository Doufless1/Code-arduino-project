//
// Created by onno1 on 28/04/2024.
//

#include <Arduino.h>
#include <Servo.h>
#include "steering.h"

const int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
const int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)

void steering::drive(int speed,bool direction){
    if(direction){
        // forward rotation
        analogWrite(LPWM_Output, speed);
        analogWrite(RPWM_Output, 0);
    }else{
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, speed);
    }
}

void steering::steer(int angle){
    //make sure angle is within movement range
    int temp=angle+angle_;

    if (temp<min)angle_=75;
    else if (temp>max)angle_=105;

    angle_=temp;

    myServo.write(angle_);  // Set the servo position
}

int steering::get_angle() {
    return angle_;
}

void steering::set_straight() {
    int angle=get_angle();
    angle_=90-angle;
}
