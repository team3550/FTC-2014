#pragma systemfile
#define _Gemini_Sensors_

//========== Defines ==========

//========== Prototypes ==========
word sensorsUltrasonicGetDistance();

word sensorsIRGetDirection();

word sensorsLightGetReflected();

void  sensorsGyroInitialize();
float sensorsGyroGetRate();
void  sensorsGyroCalibrateOffset();
void  sensorsGyroCalibrateDrift();
float sensorsGyroIntegrate();
float sensorsGyroGetHeading();
void  sensorsGyroResetHeading();
task  sensorsGyroIntegrateTask();
void  sensorsGyroStartIntegrateTask();
void  sensorsGyroStopIntegrateTask();

//========== Variables ==========
bool  isGyroIntegrationTaskRunning = false;
float gyroHeading = 0;
float gyroOffset = 0;
float gyroDriftRate = 0;
long  gyroLastTimestamp = 0;

//========== Functions ==========
void sensorsGyroInitialize() {
  gyroHeading = 0;
  sensorsGyroCalibrateOffset();
  sensorsGyroCalibrateDrift();
}

float sensorsGyroGetRate() {
  return SensorValue[HTGyro] - gyroOffset;
}

void sensorsGyroCalibrateOffset() { //calibrate the gyro offset
  PlayImmediateTone(4186, 50);
  eraseDisplay();
  nxtDisplayCenteredTextLine(1, "Calibrating: \n Gyro Offset");
  wait1Msec(1000);

  int offsetSum = 0;
  int range = 100;
  for(int i = 0; i < range; i++) {
    offsetSum += sensorsGyroGetRate();
  }
  gyroOffset = (offsetSum / range);

  eraseDisplay();
  nxtDisplayCenteredTextLine(1, "Done");
  wait1Msec(500);
  eraseDisplay();
}

void sensorsGyroCalibrateDrift() {
  PlayImmediateTone(4186, 50);
  eraseDisplay();
  nxtDisplayCenteredTextLine(1, "Calibrating: \n Gyro Drift Rate");

  long gyroCurrentTimestamp = 0;    //setup timestamp variable
  gyroDriftRate = 0;                //reset drift rate
  int samples = 2000;               //number of samples to collect
  float tempHeading = 0;            //holds change in heading while robot is calibrating
  long startTime = nSysTime;        //set start time at the start of collecting samples

  for (int i = 0; i < samples; i++) {
    tempHeading += sensorsGyroIntegrate();      //integrate the heading over a give # of samples to estimate drift
  }

  gyroDriftRate = (tempHeading / ((nSysTime - startTime)/1000)); //drift rate = change in heading over change in time while collecting samples
}

float sensorsGyroIntegrate() {
  long  gyroCurrentTimestamp = nSysTime;                             //get the current timestamp
  float  deltaT = (gyroCurrentTimestamp - gyroLastTimestamp) / 1000; //get the change in time in Sec

  float headingDeltaRough = (sensorsGyroGetRate() * deltaT);         //rough change in heading = Rate * time
  float estimatedDrift = (gyroDriftRate * deltaT);                   //estimated drift = driftRate * time

  gyroHeading += (headingDeltaRough - estimatedDrift);               //recalculate heading by adding change in heading and removing estimated drift error
  gyroLastTimestamp = gyroCurrentTimestamp;                          //update timestamp

  return (headingDeltaRough - estimatedDrift);                       //return change in heading with drift compensation
}

float sensorsGyroGetHeading() {
  return gyroHeading;
}

void sensorsGyroResetHeading() {
  gyroHeading = 0;
}

task sensorsGyroIntegrateTask() {
  isGyroIntegrateTaskRunning = true;
  while(isGyroIntegrationTaskRunning != false) {
    sensorsGyroIntegrate();
  }
 isGyroIntegrationTaskRunning = false;
}

void sensorsGyroStartIntegrateTask() {
  StartTask(sensorsGyroIntegrateTask);
}

void sensorsGyroStopIntegrateTask() {
  isGyroIntegrationTaskRunning = false;
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
