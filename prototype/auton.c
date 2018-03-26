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
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, true);
  core(-100, true);
  claw(400, true);
  core(100, false);
  flip(-1, true);
  core(-100, false);
  claw(-700, true);
  core(100, true);
  claw(-700, false);
  flip(1, false);
  moveCenter(-1500, false);
  while(!FILP_UP_SWITCH) {}
  claw(700, true);
  core(100, true);
  flip(-1, false);
  core(-100, false);
  turn(45 * side);
  claw(-700, true);
  core(100, false);
  flip(1, true);
  claw(400, true);

}

void auton20Short(int side) { // 3 cones on a MB in the 20 pt zone
  resetEncoders();


}

void auton20(int side) { // 2 cones on a MB in the 20 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, true);
  core(-100, true);
  claw(400, true);
  core(100, false);
  flip(-1, true);
  core(-100, false);
  claw(-700, true);
  core(100, true);
  claw(-700, false);
  flip(1, false);
  moveCenter(-1700, false);
  while(!FILP_UP_SWITCH) {}
  claw(700, true);
  core(100, false);
  turn(135 * side);
  moveCenter(650, true);
  turn(90 * side);
  manipulate(1, false);
  moveCenter(600, 127, true);
  moveCenter(-400, true);


}



void auton5long(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();

}

void auton5Short(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(400 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, false);
  while(500 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-800, 127, false);
  while(!manipulator.canMove) {}
  turn(45 * side, false);
  core(-100, false);
  claw(400, true);

  core(200, true);
  flip(-1, true);
  core(-100, false);
  claw(-400, true);
  core(150, false);
  flip(1, true);
  core(-100, false);
  claw(500, true);

  core(200, true);
  flip(-1, true);
  core(-100, false);
  claw(-400, true);
  core(150, false);
  flip(1, true);
  core(-100, false);
  claw(500, true);

  core(250, true);
  flip(-1, true);
  core(-100, false);
  claw(-400, true);
  core(150, false);
  flip(1, true);
  core(-100, false);
  claw(500, true);

  core(250, false);
  flip(-1, true);
  core(-200, false);
  claw(-400, true);
  core(100, false);
  turn(90 * side, false);
  flip(1, true);
  core(-100, false);
  claw(500, true);

  core(250, false);
  manipulate(1, true);
  driveF(-127);
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
