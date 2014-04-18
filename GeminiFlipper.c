#pragma systemfile

//========== defines ==========
#define Flipper servo6

//========== prototypes ==========
void flipperInitialize();

void flipperToPosition(byte pos);
void flipperStorage();
void flipperReady();
void flipperReadySlow();
void flipperDump();
void fippperDumpSlow();

//========== variables ==========
byte flipperPositionStorage = 255;
byte flipperPositionReady = 255;
byte flipperPositionDump = 255;

//========== functions ==========
void flipperInitialize() {  //Initialize the flipper for driving

}

void flipperToPosition(byte pos) {  //puts the flipper servo at a specific position

}

void flipperStorage() {     //Put the flipper in the storage position

}

void flipperReady() {       //Put the flipper in the ready position

}

void flipperReadySlow() {   //Put the flipper in the ready position, but change the update rate

}

void flipperDump() {        //Put the flipper in the dump position

}

void flipperDumpslow() {    //Put the flipper in the dump position, but change the update rate

}
