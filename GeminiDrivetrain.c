#pragma systemFile
#define _Gemini_Drivetrain_

#ifndef _Gemini_Gyro_
#include "GeminiGyro.c"
#endif

#ifndef _Gemini_Sensors_
#include "GeminiSensors.c"
#endif

//========== DEFINES ==========
#define Kp_hdghold 4

//========== prototypes ==========
void driveInitialize();

void driveMotors(int leftPower, int rightPower);
void driveStop();
void driveForwardPower(int power);
void driveSpinLeftPower(int power);
void driveSpinRightPower(int power);
void driveSwingLeftPower(int power);
void driveSwingRightPower(int power);

void driveUltrasonicDistanceHeadingHold(int power, int dist, bool stopWhenDone = true);
void driveSpinToHeading(float targetHeading);

void calculateDrive(int xAxis, int yAxis);
void driveSetPower(int power);

//========== variables ==========
int drivePower = 100;

//========== functions ==========
void driveInitialize() {    //initialize the drivetrain
  //do nothing
}

void driveMotors(int leftPower, int rightPower) {
  if (leftPower > 100) { leftPower = 100; }       //coerce leftPower values
  else if (leftPower < -100) { leftPower = -100; }

  if (rightPower > 100) { rightPower = 100; }     //coerce rightPower values
  else if (rightPower < -100) { rightPower = -100; }

  motor[LeftFront] = leftPower;
  motor[LeftBack] = leftPower;
  motor[RightFront] = rightPower;
  motor[RightBack] = rightPower;
}

void driveStop() {
  driveForwardPower(0);
}

void driveForwardPower(int power) {
  driveMotors(power, power);
}

void driveSpinLeftPower(int power) {
  driveMotors(-power, power);
}

void driveSpinRightPower(int power) {
  driveMotors(power, -power);
}

void driveSwingLeftPower(int power) {
  if(power > 0) {
    driveMotors(0, power);
  } else {
    driveMotors(power, 0);
  }
}

void driveSwingRightPower(int power) {
  if(power > 0) {
    driveMotors(power, 0);
  } else {
    driveMotors(0, power);
  }
}

void driveUltrasonicDistanceHeadingHold(int power, int dist, bool stopWhenDone) {
  if (isGyroIntegrateTaskRunning != true) {
    sensorsGyroStartIntegrateTask();
  }

  bool stopLoop = false;
  float headingToHold = sensorsGyroGetHeading();
  while (stopLoop != true) {
	  sensorsGyroIntegrate();                   //update current heading
	  float headingError = sensorsGyroGetHeading() - headingToHold; //calculate how far the robot is off

	  int powerLeft = power + (headingError*Kp_hdghold);  //P term loop for heading
 	  int powerRight = power - (headingError*Kp_hdghold); //hold
	  driveMotors(powerLeft, powerRight);

	  if (power > 0) {
	    stopLoop = (sensorsUltrasonicGetDistance() > dist); //robot is driving forward
	  } else {
	    stopLoop = (sensorsUltrasonicGetDistance() < dist); //robot is driving backwards
	  }
  }

  if (stopWhenDone) {
    driveStop();
  }
}

void driveSpinToHeading(float targetHeading) {  //-values are clockwise, +values are cclockwise
  if (isGyroIntegrateTaskRunning != true) {
    sensorsGyroStartIntegrateTask();
  }

  int direction = targetHeading - sensorsGyroGetHeading();
  bool stopLoop = false;
  while (stopLoop != true) {      //TODO: add code to move motors when less sleepy
    sensorsGyroIntegrate();
    if (direction > 0) {  //rotate left
      stopLoop = ((targetHeading - sensorsGyroGetHeading()) > 0);
    } else {              //rotate right
      stopLoop = ((targetHeading - sensorsGyroGetHeading()) < 0);
    }
  }
  driveStop();

  stopLoop = false;
  while (stopLoop != true) {      //TODO: add code to move motors when less sleepy
    sensorsGyroIntegrate();
    if (direction > 0) {  //rotate left
      stopLoop = ((targetHeading - sensorsGyroGetHeading()) > 0);
    } else {              //rotate right
      stopLoop = ((targetHeading - sensorsGyroGetHeading()) < 0);
    }
  }
  driveStop();
}

void calculateDrive(int xAxis, int yAxis) {
  //deadband
  if (abs(xAxis) < 10) {
    xAxis = 0;
  }
  if (abs(yAxis) < 10) {
    yAxis = 0;
  }

  //motor Scaling
  xAxis = (int)(xAxis*drivePower/127);
  yAxis = (int)(yAxis*drivePower/127);

  int leftVal = yAxis + xAxis;
  int rightVal = yAxis - xAxis;

  driveMotors(leftVal, rightVal);
}

void driveSetPower(int power) {
  drivePower = power;
}
