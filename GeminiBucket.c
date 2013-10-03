#pragma systemFile

bucketCollect() {
  //set the bucket to collection position for scooping up blocks
}

bucketStorage() {
  //set the bucket to the storage position
}

bucketCarry() {
  //set the bucket to the carrying position to keep blocks in
}

bucketFloat() {
  //turn off power to the servo motor to allow the bucket to float
}

bucketDump() {
  //set the bucket to the dumping position
}

bucketIncrementPosition(int value) {
  //increment the current position by a given value
  //Servo[bucket] += value;
  //check for bounds
}

bucketDecrementPosition(int value) {
  //decrements the current position by a given value
  //Servo[bucket] -= value;
  //check for bounds
}
