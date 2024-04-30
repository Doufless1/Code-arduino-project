//
// Created by onno1 on 28/04/2024.
//

#ifndef PROJECT_SYSTEMS_LINE_H
#define PROJECT_SYSTEMS_LINE_H


class line {
#include <Arduino.h>

    struct ir_val{

       bool sensor1=false;
       bool sensor2=false;
       bool sensor3=false;
       bool sensor4=false;

    }ir_values;

    //using ir sensores will retrun true if there is a line and updates the ir sensor array values accordingly
    bool is_line(bool *ir_values);

    //based on ir_values will adjust steering as needed
    steer_adjust(bool *ir_values);

    //gets the angle of the incline and returns it
    int get_rise();

    //if the rise angle is over x returns true
    bool is_ramp(int rise);

    //will adjust speed of the car based on angle
    int ramp_speed(int rise);


    //when car is at the end of the track retruns true;
    bool is_end(bool *ir_values);

};


#endif //PROJECT_SYSTEMS_LINE_H
