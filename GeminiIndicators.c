#pragma systemFile

#include "drivers/hitechnic-superpro.h"

//========== defines ==========
#define HTSPBDOutMask 0xFF  //TODO: update this number to have the appropriate DOut mask
#define RSLOnMask 0x01;  //0b00000001
#define RSLOffMask 0xFE; //0b11111110
//========== prototypes ==========
void IndicatorsInitialize();

void RSLOn();
void RSLOff();
void RSLBlinkTeleop();
void RSLBlinkAutonomous();
void RSLBlinkDisabled();
void RSLBlinkLowBattery();
void RSLBlinkError();

//========== variables ==========
byte HTSPBDOut = 0x00;
//========== functions ==========

void IndicatorsInitialize() {
  HTSPBsetupIO(HTSPB, HTSPBDOutMask);
}

void RSLOn() {
  motor[rsl] = 100;
  //Update Super Pro IO bits
  HTSPBDOut |= RSLOnMask;
  HTSPBwriteIO(HTSPB, HTSPBDOut);
}

void RSLOff() {
  motor[rsl] = 0;
  //update Super Pro
  HTSPBDOut &= RSLOffMask;
  HTSPBwriteIO(HTSPB, HTSPBDOut);
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
