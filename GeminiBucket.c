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

int bucketPosition(int action) {
  //implements a state machine to transition betwen different positions
  switch(currentPosition) {
    case posCollect:
      switch(action) {
        case nextPos:
          break;
        case prevPos:
          break;
        default:
          //do nothing
      } break;
      
    case posStorage:
      switch(action) {
        case nextPos:
          break;
        case prevPos:
          break;
        default:
          //do nothing
      } break;
      
      case posCarry:
        switch(action) {
         case nextPos:
           break;
          case prevPos:
            break;
          default:
          //do nothing
      } break;
      
    case posFloat:
      switch(action) {
        case nextPos:
          break;
        case prevPos:
          break;
        default:
        //do nothing
      } break;
      
    case posDump:
      switch(action) {
        case nextPos:
          break;
        case prevPos:
          break;
        default:
          //do nothing
      } break;
      
    default:
      //do nothing
  }
}

bucketIncrementAngle(int value) {
  //increment the current position by a given value
  //Servo[bucket] += value;
  //check for bounds
}

bucketDecrementAngle(int value) {
  //decrements the current position by a given value
  //Servo[bucket] -= value;
  //check for bounds
}
