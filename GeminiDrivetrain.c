#pragma systemFile

//========== DEFINES ==========

//========== prototypes ==========

//========== variables ==========
int drivePower = 100;

//========== functions ==========

void driveMotors(int leftPower, int rightPower) {
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
  int leftOverflow = 0;
  int rightOverflow = 0;


  driveMotors(leftVal, rightVal);
}

void setDrivePower(int power) {
  drivePower = power;
}
