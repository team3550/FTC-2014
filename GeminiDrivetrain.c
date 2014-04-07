#pragma systemFile

#ifndef __GEMINI_DRIVERS__
#include "gemini-drivers.h"
#endif

//========== DEFINES ==========

//========== prototypes ==========

//========== variables ==========

//========== functions ==========


void setLeftSideSpeed(int speed) {
  //need to add code to set motors to speed
  motor[leftDriveA] = speed;
  motor[leftDriveB] = speed;
  motor[leftDriveC] = speed;
}

void setRightSideSpeed(int speed) {
  //need to add code to set motors to speed
  motor[rightDriveA] = speed;
  motor[rightDriveB] = speed;
  motor[rightDriveC] = speed;
}

void setLeftSidePower(int power) {
  //need to add code to set motors to power
  motor[leftDriveA] = power;
  motor[leftDriveB] = power;
  motor[leftDriveC] = power;
}

void setRightSidePower(int power) {
  //need to add code to set motors to power
  motor[rightDriveA] = power;
  motor[rightDriveB] = power;
  motor[rightDriveC] = power;
}

void driveForwardSpeed(int speed) {
  setLeftSideSpeed(speed);
  setRightSideSpeed(speed);
}

void driveForwardPower(int power) {
  setLeftSidePower(power);
  setRightSidePower(power);
}

void driveBackwardSpeed(int speed) {
  setLeftSideSpeed(speed);
  setRightSideSpeed(speed);
}

void driveBackwardPower(int power) {
  setLeftSidePower(power);
  setRightSidePower(power);
}
