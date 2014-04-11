#pragma systemFile

//========== prototypes ==========
void liftUpSpeed(int speed);
void liftDownSpeed(int speed);
void liftStop();
void liftResetPosition();
void liftBottomPositionSafety();
void liftDumpPositionSafety();
void liftHangPositionSafety();

//========== variables ==========

//========== functions ==========
void liftUpSpeed(int speed){
  //moves the lift up at a given speed
  motor[Lift] = speed;
}

void liftDownSpeed(int speed) {
  motor[Lift] = -speed;
  //moves the lift down at a given speed
}

void liftStop() {
  //stops the lift
  motor[Lift] = 0;
}

void liftResetPosition() {
  nMotorEncoder[Lift] = 0;
}

void liftBottomPositionSafety() {
  //moves the lift to the bottom position
  if (nMotorEncoder[Lift] > 0) {
    liftDownSpeed(50);
  } else {
    liftStop();
  }
}

void liftDumpPositionSafety() {
  //moves the lift to the Dumping position
  if (nMotorEncoder[Lift] < 4500) {
    liftUpSpeed(100);
  } else {
    liftStop();
  }
}

void liftHangPositionSafety() {
  //moves the lift to the Hanging position
  if (nMotorEncoder[Lift] < 3500) {
    liftUpSpeed(100);
  } else {
    liftStop();
  }
}
