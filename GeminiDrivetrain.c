#pragma systemFile

#include "gemini-drivers.h"

//========== DEFINES ==========

//========== prototypes ==========

//========== variables ==========

//========== functions ==========

void driveMotors(int leftPower, int rightPower) {
  motor[LeftFront] = leftPower;
  motor[LeftBack] = leftPower;
  motor[RightFront] = rightPower;
  motor[RightBack] = rightPower;
}

void driveForwardPower(int power) {
  driveMotors(power, power);
}

void spinLeftPower(int power) {
  driveMotors(-power, power);
}

void spinRightPower(int power) {
  driveMotors(power, -power);
}

void swingLeftPower(int power) {
  if(power > 0) {
    driveMotors(0, power);
  } else {
    driveMotors(power, 0);
  }
}

void swingRightPower(int power) {
  if(power > 0) {
    driveMotors(power, 0);
  } else {
    driveMotors(0, power);
  }
}
