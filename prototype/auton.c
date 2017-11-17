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

void auton22ptRight() { // not actual auton skills

  resetEncoders();

  core(300, false);
  manipulate(1, false);
  moveForward(600, 80, false);

  turn(10, -40, true);
  moveForward(600, 80, true);

  manipulate(-1, true); // pickup base
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false); // end of put cone on base

  moveForward(1200, -80, true);

  turn(70, -40, true);
  moveForward(500, 40, true);
  turn(80, -40, true);

  moveForward(650, 80, true);
  manipulate(1, true);
  moveForward(600, -80, true);
  manipulate(-1, true);

  turn(80, -40, true);

  flip(-1, true);

  moveForward(100, -40, true);
  moveForward(1000, -80, true);

  wait1Msec(100);
  gyroZero();

  moveForward(250, 80, true);

  flip(1, true);
  manipulate(1, true);

  turn(50, -40, true);

  moveForward(450, 80, true);
  manipulate(-1, true);

  turn(200, -40, true);
  moveForward(1150, 80, true);

  manipulate(1, true);
  moveForward(300, -80, true);

}


void auton22aptRight() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1600, 80, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1600, -80, true);

  turn(145, 40, true);

  moveForward(800, 80, true);
  manipulate(1, true);

  moveForward(500, -80, false);
  manipulate(-1, false);

  moveForward(300, -80, true);

}

void auton7ptRight() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 80, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1300, -80, true);

  turn(300, 80, true);


  manipulate(1, true);

  moveForward(300, -80, false);

  manipulate(-1, false);

}

void auton22ptLeft() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 80, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1600, -80, true);

  turn(300, 80, true);

  moveForward(550, 80, true);
  manipulate(1, true);

  moveForward(500, -80, true);
  manipulate(-1, false);




  moveForward(300, -80, true);

}

void auton7ptLeft() {

  resetEncoders();


  core(300, false);
  manipulate(1, false);
  moveForward(1500, 80, true);

  manipulate(-1, true);
  flip(-1, true);
  claw(-120, true);
  flip(1, true);
  claw(80, false);

  moveForward(1300, -80, true);

  turn(-300, 80, true);


  manipulate(1, true);

  moveForward(300, -80, false);

  manipulate(-1, false);

}

void skills() {
  turn(90, 40,  false);
}



#endif
