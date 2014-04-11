#pragma systemFile

//========== defines ==========
#define Turntable servo4

#define SPINNER_POS_IN 255
#define SPINNER_POS_OUT 255

//========== prototypes ==========
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
}

void spinnerAlignCClockwise() {
  spinnerSpin(-15);
}




