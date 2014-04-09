//========== includes ==========
#include "JoystickDriver.c"

//========== defines ==========
#define BUTTON_X 1
#define BUTTON_A 2
#define BUTTON_B 3
#define BUTTON_Y 4
#define BUTTON_RB 6
#define BUTTON_RT 8
#define BUTTON_LB 5
#define BUTTON_LT 7
#define BUTTON_BACK 9
#define BUTTON_START 10
#define BUTTON_LSTICK 11
#define BUTTON_RSTICK 12

//========== variables ==========
bool robotEnabled = false;

//========== declarations ==========
void updateControllers();
//int Controller1GetDirection();
//========== definitions ==========
void updateControllers() {
  robotEnabled = !joystick.StopPgm;
}
