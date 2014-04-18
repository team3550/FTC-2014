#pragma systemFile
#define _Controller_

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

#define BUTTON_HAT_UP         0
#define BUTTON_HAT_UPRIGHT    1
#define BUTTON_HAT_RIGHT      2
#define BUTTON_HAT_DOWNRIGHT  3
#define BUTTON_HAT_DOWN       4
#define BUTTON_HAT_DOWNLEFT   5
#define BUTTON_HAT_LEFT       6
#define BUTTON_HAT_UPLEFT     7

#define CONTROLLER_1 1
#define CONTROLLER_2 2

//========== variables ==========
bool robotEnabled = false;
short joy1_Buttons_Last = 0;
short joy2_Buttons_Last = 0;
short joy1_TopHat_Last = 0;
short joy2_TopHat_Last = 0;

//========== declarations ==========
void updateControllers();
bool ControllerButtonPressed(int button, int controller);
bool ControllerButtonReleased(int button, int controller);
bool ControllerButtonDown(int button, int controller);
bool ControllerHatPressed(int direction, int controller);
bool ControllerHatReleased(int direction, int controller);
bool ControllerHatDown(int direction, int controller);

//========== definitions ==========
void updateControllers() {
  joy1_Buttons_Last = joystick.joy1_Buttons;
  joy2_Buttons_Last = joystick.joy2_Buttons;
  joy1_TopHat_Last = joystick.joy1_TopHat;
  joy2_TopHat_Last = joystick.joy1_TopHat;

  getJoystickSettings(joystick);
  robotEnabled = !joystick.StopPgm;
}

bool ControllerButtonPressed(int button, int controller) {
  bool isPressed = false;
  bool wasPressed = false;
  switch(controller) {
    case 1 :
      isPressed = ( ((joystick.joy1_Buttons)&(1 << (button-1))) != 0);
      wasPressed = ( ((joy1_Buttons_Last)&(1 << (button-1))) != 0);
      break;
    case 2 :
      isPressed = ( ((joystick.joy2_Buttons)&(1 << (button-1))) != 0);
      wasPressed = ( ((joy2_Buttons_Last)&(1 << (button-1))) != 0);
      break;
  }
  return ((isPressed == true) && (wasPressed == false));
}

bool ControllerButtonReleased(int button, int controller) {
  bool isPressed = false;
  bool wasPressed = false;
  switch(controller) {
    case 1 :
      isPressed = ( ((joystick.joy1_Buttons)&(1 << (button-1))) != 0);
      wasPressed = ( ((joy1_Buttons_Last)&(1 << (button-1))) != 0);
      break;
    case 2 :
      isPressed = ( ((joystick.joy2_Buttons)&(1 << (button-1))) != 0);
      wasPressed = ( ((joy2_Buttons_Last)&(1 << (button-1))) != 0);
      break;
  }
  return ((isPressed == false) && (wasPressed == true));
}

bool ControllerButtonDown(int button, int controller) {
  bool isPressed = false;
  switch(controller) {
    case 1:
      isPressed = ( ((joystick.joy1_Buttons)&(1 << (button-1))) != 0);
      break;
    case 2:
      isPressed = ( ((joystick.joy2_Buttons)&(1 << (button-1))) != 0);
      break;
  }
  return isPressed;
}

bool ControllerHatPressed(int direction, int controller) {
  bool isPressed = false;
  bool wasPressed = false;

  switch(controller) {
    case 1:
      isPressed = (joystick.joy1_TopHat == direction);
      wasPressed = (joy1_TopHat_Last == direction);
      break;
    case 2:
      isPressed = (joystick.joy2_TopHat == direction);
      wasPressed = (joy2_TopHat_Last == direction);
  }

  return ((isPressed == true) && (wasPressed == false));
}

bool ControllerHatReleased(int direction, int controller) {
  bool isPressed = false;
  bool wasPressed = false;

  switch(controller) {
    case 1:
      isPressed = (joystick.joy1_TopHat == direction);
      wasPressed = (joy1_TopHat_Last == direction);
      break;
    case 2:
      isPressed = (joystick.joy2_TopHat == direction);
      wasPressed = (joy1_TopHat_Last == direction);
      break;
  }

  return ((isPressed == false) && (wasPressed == true));
}

bool ControllerHatDown(int direction, int controller) {
  bool isPressed = false;

  switch(controller) {
    case 1:
      isPressed = (joystick.joy1_TopHat == direction);
      break;
    case 2:
      isPressed = (joystick.joy2_TopHat == direction);
      break;
  }

  return isPressed;
}
