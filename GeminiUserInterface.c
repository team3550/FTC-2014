#pragma systemFile


//========== defines ==========
#define NXT_BUTTON_ENTER  2
#define NXT_BUTTON_LEFT   2
#define NXT_BUTTON_RIGHT  2
#define NXT_BUTTON_BACK   2

//========== prototypes ==========
void promptTimeDelay(int maxTime = 30000);
void promptAutonomousMode();

//========== variables ==========
long autoDelayTime = 0;
long autoDelayTimeStep = 1000;
string autoMode = "";

//========== functions ==========
void promptTimeDelay(int maxTime) {
  eraseDisplay();
  nxtDisplayCenteredTextLine(3, "Delay Time:");
  nxtDisplayCenteredTextLine(8, "- Dec.     Inc. +");

  int nNxtButtonPressedOld = -1;
  while (nNxtButtonPressed != NXT_BUTTON_ENTER) {

    if ((nNxtButtonPressed == NXT_BUTTON_LEFT) && (nNxtButtonPressedOld != NXT_BUTTON_LEFT)) {
      if ((autoDelayTime - autoDelayTimeStep) >= 0) {
        autoDelayTime -= autoDelayTimeStep;
      } else {
        autoDelayTime = 0;
      }
    } else if ((nNxtButtonPressed == NXT_BUTTON_LEFT) && (nNxtButtonPressedOld != NXT_BUTTON_LEFT)) {
      if ((autoDelayTime + autoDelayTimeStep) <= maxTime) {
        autoDelayTime += autoDelayTimeStep;
      } else {
        autoDelayTime = maxTime;
      }
    }
    nxtDisplayCenteredTextLine(6, "%f Sec.", (autoDelayTime/1000));
  }
}
