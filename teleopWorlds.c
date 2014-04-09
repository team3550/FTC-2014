#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          rsl,           tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C1_1,     LeftFront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C1_2,     LeftBack,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S4_C2_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     RightBack,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C3_1,     Lift,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S4_C3_2,     Spinner,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C4_1,    BucketRight,          tServoStandard)
#pragma config(Servo,  srvo_S4_C4_2,    PTO,                  tServoStandard)
#pragma config(Servo,  srvo_S4_C4_3,    BucketLeft,           tServoStandard)
#pragma config(Servo,  srvo_S4_C4_4,    Turntable,            tServoStandard)
#pragma config(Servo,  srvo_S4_C4_5,    Ratchet,              tServoStandard)
#pragma config(Servo,  srvo_S4_C4_6,    Flipper,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define BUTTON_X 1
#define BUTTON_A 2
#define BUTTON_B 3
#define BUTTON_Y 4
#define BUTTON_RB 6
#define BUTTON_RT 8
#define BUTTON_LB 5
#define BUTTON_LT 7
#define BUTTON_BACK
#define BUTTON_START
#define BUTTON_LSTICK
#define BUTTON_RSTICK

#include "GeminiDrivetrain.c"

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


void initializeRobot()
{
  clearDebugStream();
  return;
}


task main()
{
  initializeRobot();
  waitForStart();   // wait for start of tele-op phase

  while (true)
  {
    if (!joystick.StopPgm) {
      //========== ENABLED ==========
      calculateDrive(joystick.joy1_x1, joystick.joy1_y1);

      //TODO: change to event based
      if(joy1Btn(BUTTON_LB)) {
        setDrivePower(30);
      } else {
        setDrivePower(100);
      }
    } else {
      //========== DISABLED ==========
    }
  }
}
