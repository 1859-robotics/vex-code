#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

#define FLIP_AMT 400

// requires: null
// modifies: null
// affects:  all encoders are set to 0 for accurate readout
void resetEncoders() {
  EncoderSetValue(LB_DRIVE, 0);
  EncoderSetValue(RB_DRIVE, 0);

  EncoderSetValue(MANIPULATOR, 0);

  EncoderSetValue(FLIP_LIFT, 0);
  EncoderSetValue(B_CORE_LIFT, 0);
  EncoderSetValue(LIFT_CLAW, 0);

}

/*************************************************************
 *                                                           *
 *      each of the following functions is an autonomas      *
 *                                                           *
 *************************************************************/

void auton20Long(int side) { // 3 cones on a MB in the 20 pt zone
  resetEncoders();

}

void auton20Short(int side) { // 3 cones on a MB in the 20 pt zone
  resetEncoders();

}

void auton5long(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();

}

void auton5Short(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();

}

void auton10long(int side) { // 4 cones on a MB in the 5 pt zone
  resetEncoders();

}

void auton10Short(int side) { // 4 cones on a MB in the 5 pt zone
  resetEncoders();

}

void autonStatLong(int side) { // 2 cones on the stationary goal + tip a MB
  resetEncoders();

}

void autonStatShort(int side) { // 2 cones on the stationary goal + tip a MB
  resetEncoders();

}

void autonSabatoge(int side) {
  resetEncoders();
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(400);
  turn(45 * side);
  driveF(127);
  wait1Msec(2500);
  driveF(0);
}




/******************************************************************************/







void skills() {

}

#endif
