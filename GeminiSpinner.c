#pragma systemFile

//========== defines ==========
#define Turntable servo4

#define SPINNER_POS_IN 255
#define SPINNER_POS_OUT 255
#define SPINNER_TIME_EIGTH_TURN 20

//========== prototypes ==========
void spinnerInitialize();

void spinnerIn();
void spinnerOut();
void spinnerSpin(int power);
void spinnerStop();
void spinnerSpinClockwise();
void spinnerSpinCClockwise();
void spinnerAlignClockwise();
void spinnerAlignCClockwise();

//========== variables ==========


//========== functions ==========
void spinnerInitialize() {
  spinnerStop();
  spinnerIn();
  writeDebugStreamLine("Initialized: Spinner");
}

void spinnerIn() {
  servo[Turntable] = SPINNER_POS_IN;
}

void spinnerOut() {
  servo[Turntable] = SPINNER_POS_OUT;
}

void spinnerSpin(int power) {
  motor[Spinner] = power;
}

void spinnerStop() {
  motorSpinner = 0;
}

void spinnerSpinClockwise() {
  spinnerSpin(100);
}

void spinnerSpinCClockwise() {
  spinnerSpin(-100);
}

void spinnerAlignClockwise() {
  spinnerSpin(15);
  wait1Msec(SPINNER_TIME_EIGTH_TURN);
  spinnerStop();
}

void spinnerAlignCClockwise() {
  spinnerSpin(-15);
  wait1Msec(SPINNER_TIME_EIGTH_TURN);
  spinnerStop();
}




