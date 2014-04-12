#pragma systemFile

#define BucketLeft servo3
#define BucketRight servo1

//========== Prototypes ==========
void bucketInitialize();

void bucketStorage();
void bucketCollect();
void bucketFloat();
void bucketDump();
void bucketIncrementState();
void bucketDecrementState();
void bucketTrimUp();
void bucketTrimDown();


//========== Variables ==========
int trim = 0;

typedef enum bucketStates {
  bucketStateStorage = 0,
  bucketStateCollect = 1,
  bucketStateFloat = 2,
  bucketStateDump = 3,
} bucketStates;

bucketStates bucketState = bucketStateStorage;

int bucketLeftStorage = 228;
int bucketLeftCollect = 100;
int bucketLeftDump    = 30;

int bucketRightStorage = 13;
int bucketRightCollect = 140;
int bucketRightDump    = 219;

//========== Functions ==========
void bucketInitialize() {
  bucketStorage();
  writeDebugStreamLine("Initialized: Bucket");
}

void bucketStorage() {
  //set the bucket to the storage position
  servo[BucketLeft] = bucketLeftStorage + trim;
  servo[BucketRight] = bucketRightStorage - trim;
  bucketState = bucketStateStorage;
}

void bucketCollect() {
  //set the bucket to collection position for scooping up blocks
  servo[BucketLeft] = bucketLeftCollect + trim;
  servo[BucketRight] = bucketRightCollect - trim;
  bucketState = bucketStateCollect;
}

void bucketFloat() {
  //turn off power to the servo motor to allow the bucket to float
  bucketState = bucketStateFloat;
}

void bucketDump() {
  //set the bucket to the dumping position
  servo[BucketLeft] = bucketLeftDump + trim;
  servo[BucketRight] = bucketRightDump - trim;
  bucketState = bucketStateDump;
}

void bucketIncrementState() {
  if (bucketState == bucketStateStorage) {
    bucketStorage();
  } else if (bucketState == bucketStateCollect) {
    bucketStorage();
  } else if (bucketState == bucketStateDump) {
    bucketCollect();
  } else {}
  writeDebugStreamLine("Bucket State: %d", bucketState);
}

void bucketDecrementState() {
  if (bucketState == bucketStateStorage) {
    bucketCollect();
  } else if (bucketState == bucketStateCollect) {
    bucketDump();
  } else if (bucketState == bucketStateDump) {
    bucketDump();
  }
  writeDebugStreamLine("Bucket State: %d", bucketState);
}

void bucketTrimUp() {
  //increments trim value
  byte leftHolder = servo[BucketLeft];
  byte rightHolder = servo[BucketRight];
  trim += 5;
  servo[BucketLeft] = leftHolder + trim;
  servo[BucketRight] = rightHolder - trim;
}
void bucketTrimDown() {
  //decrements trim value
  byte leftHolder = servo[BucketLeft];
  byte rightHolder = servo[BucketRight];
  trim -= 5;
  servo[BucketLeft] = leftHolder + trim;
  servo[BucketRight] = rightHolder - trim;
}
