#pragma systemfile
#define _Gemini_Sensors_

//========== Defines ==========

//========== Prototypes ==========
word sensorsUltrasonicGetDistance();

word sensorsIRGetDirection();

word sensorsLightGetReflected();

//========== Variables ==========

//========== Functions ==========





//=========== Old Stuff ==========

/*//read accelerometer and detect collisions
void accelerometerCallibrate() {
}

bool detectCollision() {
  //detects a sudden change in the acceleration of the robot by comparing the derivative of the slope to a known spike value

  if (deltaX || deltaY > spikeThreshold){
    return true;
  }
  else {
    return false;
  }
}


void waitForCollision() {
  while(detectCollision() == false) {
    //wait and do nothing
  }
}

void onCollision(task thisTask) {
  //detects a collision using accelerometer, and starts a specified task

  waitForCollision();
  StartTask(thisTask);
}

void gyroCallibrate() {
}

float gyroTurnRate() {
  //returns the % maximum speed that the robot is turning at
}

void lineSensorCallibrate() {
  //calibrates the sensor for the line color, ramp color, and mat color
}

float lineSensorReading() {
  //returns a %reading of the returned light value
}

int lineSensorColor() {
  //returns the best guess for the color beneath the sensor


  whiteEstimate = kWhite - reading;
  greyEstimate = kGrey - reading;
  blackEstimate = kBlack - reading;

  bestGuess = max( max(whiteEstimate, greyEstimate), blackEstimate);

  if (bestGuess == whiteEstimate) {
    return white; }
  else if (bestGuess == greyEstimate) {
    return grey;  }
  else if (bestGuess == blackEstimate) {
    return black; }
  else {
    return error; }

} */
