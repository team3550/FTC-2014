#pragma systemfile

//========== defines ==========
#define Flipper servo6
#define Flipper_Slow_Rate 2
#define Flipper_Slow_Rate_Time 100

//========== prototypes ==========
void flipperInitialize();

void flipperToPosition(byte pos);
void flipperStorage();
void flipperReady();
void flipperReadySlow();
void flipperDump();
void flipperDumpSlow();

//========== variables ==========
byte flipperPositionStorage = 12;
byte flipperPositionReady = 70;
byte flipperPositionDump = 190;

//========== functions ==========
void flipperInitialize() {  //Initialize the flipper for driving
  flipperStorage();
}

void flipperToPosition(byte pos) {  //puts the flipper servo at a specific position
  servo[Flipper] = pos;
}

void flipperStorage() {     //Put the flipper in the storage position
  flipperToPosition(flipperPositionStorage);
}

void flipperReady() {       //Put the flipper in the ready position
  flipperToPosition(flipperPositionReady);
}

void flipperReadySlow() {   //Put the flipper in the ready position, but change the update rate
  short oldRate = servoChangeRate[Flipper];
  servoChangeRate[Flipper] = Flipper_Slow_Rate;
  flipperReady();
  wait1Msec(Flipper_Slow_Rate_Time);
  servoChangeRate[Flipper] = oldRate;
}

void flipperDump() {        //Put the flipper in the dump position
  flipperToPosition(flipperPositionDump);
}

void flipperDumpSlow() {    //Put the flipper in the dump position, but change the update rate
    short oldRate = servoChangeRate[Flipper];
  servoChangeRate[Flipper] = Flipper_Slow_Rate;
  flipperDump();
  wait1Msec(Flipper_Slow_Rate_Time);
  servoChangeRate[Flipper] = oldRate;
}
