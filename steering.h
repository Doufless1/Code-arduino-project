//
// Created by onno1 on 28/04/2024.
//

#ifndef PROJECT_SYSTEMS_STEERING_H
#define PROJECT_SYSTEMS_STEERING_H

#include <Arduino.h>
class steering {

public:
    //controls the car driving direction
    //if direction is true then the car move forward
    drive(int speed,bool direction);


    //takes an angle and adjusts the steering accordingly
    steer(int angle);

};


#endif //PROJECT_SYSTEMS_STEERING_H
