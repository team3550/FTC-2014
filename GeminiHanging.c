#pragma systemfile

#ifndef _Gemini_Drivetrain_
#include "GeminiDrivetrain.c"
#endif

//========== defines ==========
#define PTO     servo2
#define Ratchet servo5

#define PTO_Position_Engaged        86
#define PTO_Position_Disengaged     126

#define Ratchet_Position_Engaged    170
#define Ratchet_Position_Disengaged 255
#define Ratchet_Time_Lock           250
#define Ratchet_Time_Unlock         250
//========== prototypes ==========
void hangingInitialize();

void hangingPTOEngage();
void hangingPTODisengage();

void hangingRatchetEngage();
void hangingRatchetDisengage();
void hangingRatchetLock();
void hangingRatchetUnlock();
//========== variables ==========

//========== functions ==========
void hangingInitialize() {  //initialze the hanging system
  hangingPTODisengage();
  hangingRatchetDisengage();
}

void hangingPTOEngage() { //Engage the PTO from the drivetrain
  servo[PTO] = PTO_Position_Engaged;
}

void hangingPTODisengage() {  //disngage the PTO from the drivetrain
  servo[PTO] = PTO_Position_Disengaged;
}

void hangingRatchetEngage() {  //engage the ratchet to the hanging shaft
  servo[Ratchet] = Ratchet_Position_Engaged;
}

void hangingRatchetDisengage() {  //disengage the ratchet from the hanging shaft
  servo[Ratchet] = Ratchet_Position_Disengaged;
}

void hangingRatchetLock() {       //Lock the ratchet by backdriving slightly
  hangingRatchetEngage();
  driveForwardPower(100);
  wait1Msec(Ratchet_Time_Lock);
  driveStop();
}

void hangingRatchetUnlock() {     //Unlock the ratchet by releasing pressure from the ratchet system
  hangingRatchetDisengage();
  driveForwardPower(100);
  wait1Msec(Ratchet_Time_Unlock);
  driveStop();
}
