//
// Created by onno1 on 28/04/2024.
//

#include "line.h"
#include <Arduino.h>

int ir1=1,ir2=2,ir3=3,ir4=4,ir5=5;

void line::get_ir_values(){
    ir_values.sensor1_=digitalRead(ir1);
    ir_values.sensor2_=digitalRead(ir2);
    ir_values.sensor3_=digitalRead(ir3);
    ir_values.sensor4_=digitalRead(ir4);
    ir_values.sensor5_=digitalRead(ir5);

}

bool line::is_line(){
    get_ir_values();
    if(ir_values.sensor1_||ir_values.sensor1_||ir_values.sensor3_||ir_values.sensor4_||ir_values.sensor5_){
        return true;
    }

    return false;
}

//based on ir_values will adjust steering as needed
int line::steer_adjust(){

    int right=12,slightRight=6;
    if (ir_values.sensor3_) { // Center sensor
        return 0;
    } else if (ir_values.sensor2_) { // Slightly left
        return -slightRight;
    } else if (ir_values.sensor4_) { // Slightly right
        return slightRight;
    } else if (ir_values.sensor1_) { // Far left
        return -right;
    } else if (ir_values.sensor5_) { // Far right
        return right;
    } else {
        // No line detected or all sensors are off the line
        return 0;
        Serial.println("Line Lost, Adjusting");
    }

}


//when car is at the end of the track retruns true;
bool line::is_end(){
    get_ir_values();
    if(ir_values.sensor1_&&ir_values.sensor1_&&ir_values.sensor3_&&ir_values.sensor4_&&ir_values.sensor5_){
        return true;
    }

    return false;
}