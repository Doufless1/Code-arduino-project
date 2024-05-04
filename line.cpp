//
// Created by onno1 on 28/04/2024.
//

#include "line.h"
#include <Arduino.h>

int ir1=1,ir2=2,ir3=3,ir4=4;

void line::get_ir_values(){
    ir_values.sensor1_=digitalRead(ir1);
    ir_values.sensor2_=digitalRead(ir2);
    ir_values.sensor3_=digitalRead(ir3);
    ir_values.sensor4_=digitalRead(ir4);
}

bool line::is_line(){
    get_ir_values();
    if(ir_values.sensor1_||ir_values.sensor1_||ir_values.sensor3_||ir_values.sensor4_){
        return true;
    }

    return false;
}

//based on ir_values will adjust steering as needed
void line::steer_adjust(){
    //what the fuck is this shit
}


//when car is at the end of the track retruns true;
bool line::is_end(){
    get_ir_values();
    if(ir_values.sensor1_&&ir_values.sensor1_&&ir_values.sensor3_&&ir_values.sensor4_){
        return true;
    }

    return false;
}