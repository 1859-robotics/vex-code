#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

// requires: null
// modifies: null
// affects:  all encoders are set to 0 for accurate readout
void resetEncoders() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  EncoderSetValue(R_MANIPULATOR, 0);

  EncoderSetValue(FLIP_LIFT, 0);
  EncoderSetValue(L_CORE_LIFT, 0);
  EncoderSetValue(LIFT_CLAW, 0);

}

void auasdaston22ptRight() { // not actual auton

  resetEncoders();

  core(300, false);
  manipulate(1, false);
  moveForward(1500, 127, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(120, false);

}


void auton22ptRight() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 127, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1600, -127, true);

  turn(135, 40, true);

  moveForward(800, 127, true);
  manipulate(1, true);

  moveForward(500, -127, false);
  manipulate(-1, false);

  moveForward(300, -127, true);

}

void auton7ptRight() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 127, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1300, -127, true);

  turn(300, 80, true);


  manipulate(1, true);

  moveForward(300, -127, false);

  manipulate(-1, false);

}

void auton22ptLeft() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 127, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1600, -127, true);

  turn(300, 80, true);

  moveForward(550, 127, true);
  manipulate(1, true);

  moveForward(500, -127, true);
  manipulate(-1, false);




  moveForward(300, -127, true);

}

void auton7ptLeft() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 127, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1300, -127, true);

  turn(-300, 80, true);


  manipulate(1, true);

  moveForward(300, -127, false);

  manipulate(-1, false);

}

void skills() {
  turn(90, 40,  false)
}



#endif
