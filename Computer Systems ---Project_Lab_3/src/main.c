#include <stdio.h>
#include <header1.h>
int main()
{
 setupGPIO();
 int state = 0;
 int prev_state = 0;

 while(1)
 {
 
while (state == 0){
    // green led
    setLED(OUTSIDE_PIN_1, ON);
    //flashing yellow led
    setLED(OUTSIDE_PIN_2, ON);
    delay(DELAY);
    setLED(OUTSIDE_PIN_2, OFF);
    delay(DELAY);
    //flashing red led
    setLED(OUTSIDE_PIN_3, ON);
    delay(DELAY);
    setLED(OUTSIDE_PIN_3, OFF);
    delay(DELAY);
    if(checkBot()){ //move to next state when the TST button isn't pushed 
        state = 1;
    }


}

while (state == 1){
    //turn on green led
    setLED(OUTSIDE_PIN_1, ON);
    //turn off yellow led
    setLED(OUTSIDE_PIN_2, OFF);
    //turn off red led
    setLED(OUTSIDE_PIN_3, OFF);
    if((!checkBot() && !checkBot2())){ //move back to previous state when TST button is pushed and the FLA switch is off
        state = 0;
    }
    if((checkBot2())){ //move to next state when FLA swtich is turned on
        state = 2;
    }


}

while (state == 2){
    //turn off green led
    setLED(OUTSIDE_PIN_1, OFF);
    //turn off red led
    setLED(OUTSIDE_PIN_3, OFF);
    //flashing yellow led
    setLED(OUTSIDE_PIN_2, ON);
    delay(DELAY);
    setLED(OUTSIDE_PIN_2, OFF);
    delay(DELAY);
    if((!checkBot2() && !checkBot3())){ //move back to previous state when FLA and OLA switch are turned off
        state = 1;
    }
    if((!checkBot3() && checkBot2() && !checkBot4())){ //move to next state when the FLA switch is turned on, the OLA switch is off and the ACK button is pressed
        state = 3;
    }
    if((checkBot3())){ //move to state 4 when the OLA switch is turned on
        state = 4;
    }


}

while (state == 3){
    //turn off green led 
    setLED(OUTSIDE_PIN_1, OFF);
    //turn off red led
    setLED(OUTSIDE_PIN_3, OFF);
    //turn on yellow led 
    setLED(OUTSIDE_PIN_2, ON);
    if((!checkBot2() && !checkBot3())){ // move back to previous state when the FLA and OLA switches are off 
        state = 2;
    }
    if((checkBot3())){ //move to next state when the FLA switch is turned on 
        state = 4;
    }
}

while (state == 4){
    //turn off green led 
    setLED(OUTSIDE_PIN_1, OFF);
    //turn off yellow led
    setLED(OUTSIDE_PIN_2, OFF);
    //flashing red led
    setLED(OUTSIDE_PIN_3, ON);
    delay(DELAY);
    setLED(OUTSIDE_PIN_3, OFF);
    delay(DELAY);

    if((!checkBot4())){ // move to next state when ACK button is pressed 
        state = 5;
    }
}
while (state == 5){
    //turn off green led 
    setLED(OUTSIDE_PIN_1, OFF);
    //turn off yellow led
    setLED(OUTSIDE_PIN_2, OFF);
    //turn on red led 
    setLED(OUTSIDE_PIN_3, ON);
    if((!checkBot3())){ // move back to state 3 when OLA switch is turned off
        state = 3;
    }
}


 }
 return 0;
}