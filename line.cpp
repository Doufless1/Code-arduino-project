//
// Created by onno1 on 28/04/2024.
//

#include "line.h"
#include <Arduino.h>


bool is_line(bool *ir_values);

//based on ir_values will adjust steering as needed
void steer_adjust(bool *ir_values);

//gets the angle of the incline and returns it
int get_rise();

//if the rise angle is over x returns true
bool is_ramp(int rise);

//will adjust speed of the car based on angle
int ramp_speed(int rise);


//when car is at the end of the track retruns true;
bool is_end(bool *ir_values);