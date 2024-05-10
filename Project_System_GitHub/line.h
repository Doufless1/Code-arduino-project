//
// Created by onno1 on 28/04/2024.
//

#ifndef PROJECT_SYSTEMS_LINE_H
#define PROJECT_SYSTEMS_LINE_H

#include <Arduino.h>
class line {



    struct ir_val{
       bool sensor1_=false;
       bool sensor2_=false;
       bool sensor3_=false;
       bool sensor4_=false;
       bool sensor5_=false;


    }ir_values;
public:
    //gets the reading of each irsensor
    void get_ir_values();

    //using ir sensores will retrun true if there is a line and updates the ir sensor array values accordingly
    bool is_line();

    //based on ir_values will adjust steering as needed
    int steer_adjust();


    //when car is at the end of the track retruns true;
    bool is_end();

    //rediscovers the line
    void search_line();

};


#endif //PROJECT_SYSTEMS_LINE_H
