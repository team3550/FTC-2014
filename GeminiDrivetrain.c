#pragma systemFile

#ifndef __GEMINI_DRIVERS__
#include "gemini-drivers.c"
#endif

//========== DEFINES ==========

//========== prototypes ==========

//========== variables ==========

//========== functions ==========


setLeftSideSpeed(int speed) {
  //need to add code to set motors to speed
  motor[leftDriveA] = speed;
  motor[leftDriveB] = speed;
  motor[leftDriveC] = speed;
}

setRightSideSpeed(int speed) {
  //need to add code to set motors to speed
  motor[rightDriveA] = speed;
  motor[rightDriveB] = speed;
  motor[rightDriveC] = speed;
}

setLeftSidePower(int power) {
  //need to add code to set motors to power
  motor[leftDriveA] = power;
  motor[leftDriveB] = power;
  motor[leftDriveC] = power;
}

setRightSidePower(int power) {
  //need to add code to set motors to power
  motor[rightDriveA] = power;
  motor[rightDriveB] = power;
  motor[rightDriveC] = power;
}

driveForwardSpeed(int speed) {
  setLeftSideSpeed(speed);
  setRightSideSpeed(speed);
}

driveForwardPower(int power) {
  setLeftSidePower(power);
  setRightSidePower(power);
}

driveBackwardSpeed(int speed) {
  setLeftSideSpeed(speed);
  setRightSideSpeed(speed);
}

driveBackwardPower(int power) {
  setLeftSidePower(power);
  setRightSidePower(power);
}
