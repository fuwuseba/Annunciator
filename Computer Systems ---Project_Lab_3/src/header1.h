#define DELAY 200
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03
#define RED_LED 0x400000
#define BLUE_LED 0x200000
#define GREEN_LED 0x080000
#define OUTSIDE_PIN_1 0x800
#define OUTSIDE_PIN_2 0x1000
#define OUTSIDE_PIN_3 0x2000
void setupGPIO();
int setLED(int color, int state);
int checkBot();
int checkBot2();
int checkBot3();
int checkBot4();
void delay(int milliseconds);
