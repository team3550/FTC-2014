#pragma systemfile
#define _Gemini_Sensors_

#ifndef __HTSMUX_H__
#include "drivers/hitechnic-sensormux.h"
#endif

#ifndef _Gemini_Gyro_
#include "GeminiGyro.c"
#endif

#ifndef __HTIRS2_H__
#include "drivers/hitechnic-irseeker-v2.h"
#endif

#ifndef __LEGOLS_H__
#include "drivers/lego-light.h"
#endif

#ifndef __LEGOUS_H__
#include "drivers/lego-ultrasound.h"
#endif

//========== Defines ==========

//========== Prototypes ==========
int sensorsUltrasonicGetDistance();

int sensorsIRGetDirection();

int sensorsLightGetReflected();
void sensorsLightLightOn();
void sensorsLightLightOff();

//========== Variables ==========
const tMUXSensor lightMUX = msensor_S3_4; //TODO: update the sensor numbers
const tMUXSensor sonarMUX = msensor_S3_1; //TODO: update the sensor numbers
const tMUXSensor IRMUX = msensor_S3_1;    //TODO: update the sensor numbers

//========== Functions ==========
int sensorsUltrasonicGetDistance() {
  return USreadDist(sonarMUX);
}

int sensorsIRGetDirection() {
  return HTIRS2readACDir(IRMUX);
}

int sensorsLightGetReflected() {
  return LSvalRaw(lightMUX);
}

void sensorsLightLightOn(){
  LSsetActive(lightMUX);
}

void sensorsLightLightOff() {
  LSsetInactive(lightMUX);
}

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
