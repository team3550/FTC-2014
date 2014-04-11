#pragma systemFile

#define BUCKETLEFTSTORAGE 255;
#define BUCKETLEFTCOLLECT 255;
#define BUCKETLEFTDUMP 255;

#define BUCKETRIGHTSTORAGE 255;
#define BUCKETRIGHTCOLLECT 255;
#define BUCKETRIGHTDUMP 255;


//========== Prototypes ==========
void bucketInitialize();

void bucketStorage();
void bucketCollect();
void bucketFloat();
void bucketDump();
void bucketIncrementPosition();
void bucketDecrementPosition();
void bucketTrimUp();
void bucketTrimDown();

//========== Variables ==========
int bucketTrim = 0;

//========== Functions ==========
void bucketInitialize() {
  bucketStorage();
  writeDebugStreamLine("Initialized: Bucket");
}

void bucketStorage() {
  //set the bucket to the storage position
}

void bucketCollect() {
  //set the bucket to collection position for scooping up blocks
}

void bucketFloat() {
  //turn off power to the servo motor to allow the bucket to float
}

void bucketDump() {
  //set the bucket to the dumping position
}

void bucketIncrementPosition(int value) {
  //increment the current position by a given value
  //Servo[bucket] += value;
  //check for bounds
}

void bucketDecrementPosition(int value) {
  //decrements the current position by a given value
  //Servo[bucket] -= value;
  //check for bounds
}

void bucketTrimUp() {
  //increments trim value
  trim += 5;
}
void bucketTrimDown() {
  //decrements trim value
  trim -= 5;
}
