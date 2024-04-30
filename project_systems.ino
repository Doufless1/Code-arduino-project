#include <Arduino.h>

int RPWM_Output = 5; // Arduino PWM output pin 5; connect to IBT-2 pin 1 (RPWM)
int LPWM_Output = 6; // Arduino PWM output pin 6; connect to IBT-2 pin 2 (LPWM)
int t=2;
void setup()
{
    pinMode(RPWM_Output, OUTPUT);
    pinMode(LPWM_Output, OUTPUT);
}

void loop() {
    static bool direction=true;

    if(direction){
        analogWrite(LPWM_Output, 30);
        analogWrite(RPWM_Output, 0);
        direction=!direction;
    }else{
        analogWrite(LPWM_Output, 0);
        analogWrite(RPWM_Output, 10);
        direction=!direction;
    }
    // forward rotation
    analogWrite(t,!);
    delay(1000)



}
