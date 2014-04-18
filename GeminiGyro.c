#pragma systemFile
#define _Gemini_Gyro_

//========== defines ==========

//========== prototypes ==========
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

//========== variables ==========
bool  isGyroIntegrateTaskRunning = false;
float gyroHeading = 0;
float gyroOffset = 0;
float gyroDriftRate = 0;
long  gyroLastTimestamp = 0;

//========== functions ==========
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
  while(isGyroIntegrateTaskRunning != false) {
    sensorsGyroIntegrate();
  }
 isGyroIntegrateTaskRunning = false;
}

void sensorsGyroStartIntegrateTask() {
  StartTask(sensorsGyroIntegrateTask);
}

void sensorsGyroStopIntegrateTask() {
  isGyroIntegrateTaskRunning = false;
}
