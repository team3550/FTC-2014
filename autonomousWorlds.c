#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          rsl,           tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C1_1,     LeftFront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C1_2,     LeftBack,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S4_C2_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     RightBack,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C4_1,     Lift,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S4_C4_2,     Spinner,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C3_1,    BucketRight,          tServoStandard)
#pragma config(Servo,  srvo_S4_C3_2,    PTO,                  tServoStandard)
#pragma config(Servo,  srvo_S4_C3_3,    BucketLeft,           tServoStandard)
#pragma config(Servo,  srvo_S4_C3_4,    Turntable,            tServoStandard)
#pragma config(Servo,  srvo_S4_C3_5,    Ratchet,              tServoStandard)
#pragma config(Servo,  srvo_S4_C3_6,    Flipper,              tServoStandard)

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
  return;
}


task main()
{
  initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.

  //auto code here

  while (true)
  {}
}
