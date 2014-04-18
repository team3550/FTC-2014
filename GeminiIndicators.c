#pragma systemFile
#define _Gemini_Indicators_

#include "drivers/hitechnic-superpro.h"

//========== defines ==========
#define HTSPBDOutMask 0xFF  //TODO: update this number to have the appropriate DOut mask

#define RSL_On   0x01
#define RSL_Off  0xFE

#define Lightbar_Enable           0x02
#define Lightbar_Disable          0xFD
#define Lightbar_Mode_Teleop      0x04
#define Lightbar_Mode_Autonomous  0xFB
#define Lightbar_Robot_Enabled    0x08
#define Lightbar_Robot_Disabled   0xF7
#define Lightbar_Endgame_Yes      0x10
#define Lightbar_Endgame_No       0xEF
//========== prototypes ==========
void IndicatorsInitialize();
void IndicatorsUpdateStates();
void IndicatorsDisable();

void RSLOn();
void RSLOff();
void RSLBlinkTeleop();
void RSLBlinkAutonomous();
void RSLBlinkDisabled();
void RSLBlinkLowBattery();
void RSLBlinkError();

void LightbarEnable();
void LightbarDisable();
void LightbarTeleop();
void LightbarAutonomous();
void LightbarRobotEnabled();
void LightbarRobotDisabled();
void LightbarEndgameYes();
void LightbarEndgameNo();

//========== variables ==========
byte DIOStates = 0x00;
//========== functions ==========

void IndicatorsInitialize() {
  HTSPBsetupIO(HTSPB, HTSPBDOutMask);
  RSLOff();
  LightbarDisable();
  LightbarAutonomous();
  LightbarRobotDisabled();
  LightbarEndgameNo();
}

void IndicatorsUpdateStates() {
  HTSPBwriteIO(HTSPB, DIOStates);
}

void IndicatorsDisable() {
  RSLOff();
  LightbarDisable();
  LightbarAutonomous();
  LightbarRobotDisabled();
  LightbarEndgameYes();
}
void RSLOn() {
  motor[rsl] = 100;
  //Update Super Pro IO bits
  DIOStates |= RSL_On;
  IndicatorsUpdateStates();
}

void RSLOff() {
  motor[rsl] = 0;
  //update Super Pro
  DIOStates &= RSL_Off;
  IndicatorsUpdateStates();
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

void LightbarEnable() {
  DIOStates |= Lightbar_Enable;
  IndicatorsUpdateStates();
}

void LightbarDisable() {
  DIOStates &= Lightbar_Disable;
  IndicatorsUpdateStates();
}

void LightbarTeleop() {
  DIOStates |= Lightbar_Mode_Teleop;
  IndicatorsUpdateStates();
}

void LightbarAutonomous() {
  DIOStates &= Lightbar_Mode_Autonomous;
  IndicatorsUpdateStates();
}

void LightbarRobotEnabled() {
  DIOStates |= Lightbar_Robot_Enabled;
  IndicatorsUpdateStates();
}

void LightbarRobotDisabled() {
  DIOStates &= Lightbar_Robot_Disabled;
  IndicatorsUpdateStates();
}

void LightbarEndgameYes() {
  DIOStates |= Lightbar_Endgame_Yes;
  IndicatorsUpdateStates();
}

void LightbarEndgameNo() {
  DIOStates &= Lightbar_Endgame_No;
  IndicatorsUpdateStates();
}
