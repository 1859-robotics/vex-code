#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

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



void auton7ptRight() {

  resetEncoders();

  core(200, true);
  manipulate(1, false);
  // moveLeftGyro(50, 40, true);

  moveCenter(50, 80, true)
  turn(45, -40, true);
  moveCenter(1400, 127, true);


  manipulate(-1, true); // pick up mobile base
  core(-100, true);
  claw(-80, true); // put cone on base

  // core(100, true);
  // flip(300, 1, true);
  // core(-100, true);
  // claw(80, true);
  // core(100, true);
  // flip(300, -1, true);
  // core(-100, true);
  // claw(-80, false); // put cone on base

  moveCenter(900, -80, true);

  turn(250, 80, true);

  core(200, true);

  manipulate(1, true);

  moveCenter(250, -80, false);

  manipulate(-1, false);

}

void auton7ptLeft() {

    resetEncoders();

    core(200, true);
    manipulate(1, false);
    // moveLeftGyro(50, 40, true);

    moveCenter(50, 80, true)
    turn(45, 40, true);
    moveCenter(1400, 127, true);


    manipulate(-1, true); // pick up mobile base
    core(-100, true);
    claw(-80, true); // put cone on base

    // core(100, true);
    // flip(300, 1, true);
    // core(-100, true);
    // claw(80, true);
    // core(100, true);
    // flip(300, -1, true);
    // core(-100, true);
    // claw(-80, false); // put cone on base

    moveCenter(900, -80, true);

    turn(180, -80, true);

    core(200, true);

    manipulate(1, true);

    moveCenter(250, -80, false);

    manipulate(-1, false);
}




#endif
