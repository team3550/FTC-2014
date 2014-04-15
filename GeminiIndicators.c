#pragma systemFile

//========== defines ==========

//========== prototypes ==========
void RSLOn();
void RSLOff();
void RSLBlinkTeleop();
void RSLBlinkAutonomous();
void RSLBlinkDisabled();
void RSLBlinkLowBattery();
void RSLBlinkError();

//========== variables ==========

//========== functions ==========

void RSLOn() {
  motor[rsl] = 100;
  //add to Super Pro IO bits
  //update Super Pro
}

void RSLOff() {
  motor[rsl] = 0;
  //add to super pro IO bits
  //reigster |= 10000
  //update Super Pro
}

void RSLBlinkTeleop() {
  RSLOn();
  wait1Msec(800);
  RSLOff();
  wait1Msec(200);
}

void RSLBlinkAutonomous(){
  RSLOn();
  wait1Msec(1000);
  RSLOff();
}

void RSLBlinkDisabled() {
  RSLOn();
  wait1Msec(500);
  RSLOff();
  wait1Msec(500);
}

void RSLBlinkLowBattery() {
  RSLOn();
  wait1Msec(200);
  RSLOff();
  wait1Msec(800);
}

void RSLBlinkError() {
  RSLOn();
  wait1Msec(250);
  RSLOff();
  wait1Msec(250);
  RSLOn();
  wait1Msec(250);
  RSLOff();
  wait1Msec(250);
}
