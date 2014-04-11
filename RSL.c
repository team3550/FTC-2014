#pragma systemFile

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

void RSLTeleopBlink() {
  RSLOn();
  wait1Msec(800);
  RSLOff();
  wait1Msec(200);
}

void RSLAutonomousBlink(){
  RSLOn();
  wait1Msec(1000);
  RSLOff();
}

void RSLDisabledBlink() {
  RSLOn();
  wait1Msec(500);
  RSLOff();
  wait1Msec(500);
}

void RSLLowBatteryBlink() {
  RSLOn();
  wait1Msec(200);
  RSLOff();
  wait1Msec(800);
}

void RSLErrorBlink() {
  RSLOn();
  wait1Msec(250);
  RSLOff();
  wait1Msec(250);
  RSLOn();
  wait1Msec(250);
  RSLOff();
  wait1Msec(250);
}
