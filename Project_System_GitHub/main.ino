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
    //loop makes the car reverse if the obsticle is too close
    while(o.get_distance()<25){
        s.drive(60,!direction);
    }

    s.steer(10);
    //s.drive(60,direction);
    unsigned long start_t=millis();
    unsigned long last_t=0;

    //2 seconds timer where car drives away from obstacle
    while(start_t-last_t<2000){
        last_t=millis();
    }

    //set car in direction of line
    s.set_straight();
    s.steer(-10);

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
            int angle =l.steer_adjust();
            s.steer(angle);
        }else if(!l.is_line())

        //increase speed if ramp is present
        if(g.is_ramp()){
            s.drive(60,direction);
        }else{s.drive(40,direction);}        //else drive default speed


    }

}
