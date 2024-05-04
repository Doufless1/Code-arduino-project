#include <Arduino.h>
#include "gyro.h"
#include "line.h"
#include "steering.h"
#include "obstacle.h"

const int button=2;
void setup() {


    Serial.begin(9600);
}


void avoid_stuff(obstacle &o, steering &s, bool direction){
    while(o.get_distance()<25){
        s.drive(60,!direction);
    }

    s.steer(20);
    s.drive(60,direction);
    unsigned long start_t=millis();
    unsigned long last_t=0;

    //2 second timer incasee things need to be eddited
    while(start_t-last_t<3000){
        last_t=millis();
    }

    s.steer(-20);

}

void loop() {
    line l;
    obstacle o;
    steering s;
    gyro g;
    //code to read the botton
    static bool button_state=false;
    const int speed=60;


    if ( digitalRead(button)) button_state=true;


    if(!l.is_end()&&button_state){
        bool direction=true; //drive direction just for readability

        if(o.is_obstacle()){
            //funtion to avoid an obstacle
            avoid_stuff(o,s,true);
        }else if(!l.is_line()){
            l.steer_adjust();
        }else if(!l.is_line())

        //increase speed if ramp is present
        if(g.is_ramp()){
            s.drive(60,direction);
        }else{s.drive(40,direction);}        //else drive default speed


    }

}
