//
// Created by onno1 on 28/04/2024.
//

#ifndef PROJECT_SYSTEMS_STEERING_H
#define PROJECT_SYSTEMS_STEERING_H

#include <Arduino.h>
class steering {
    //value to keep track of steering angle
    int angle_=90;
    const int min=75;
    const int max=105;
public:

    //controls the car driving direction
    //if direction is true then the car move forward
    void drive(int speed,bool direction);


    //takes an angle and adjusts the steering accordingly
    void steer(int angle);

    int get_angle();

    void set_straight();

};


#endif //PROJECT_SYSTEMS_STEERING_H
