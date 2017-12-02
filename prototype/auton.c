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
  moveLeftGyro(47, 40, true);

  moveCenter(950, 80, true);


  manipulate(-1, true); // pick up mobile base
  core(-100, true);
  claw(-80, true); // put cone on base

  core(100, true);
  flip(50, 1, true);
  core(-100, true);
  claw(80, true);
  core(100, true);
  flip(50, -1, true);
  core(-100, true);
  claw(-80, false); // put cone on base

  moveCenter(800, -80, true);

  turn(-200, 80, true);


  manipulate(1, true);

  moveCenter(250, -80, false);

  manipulate(-1, false);

}

void auton7ptLeft() {

  resetEncoders();

  core(300, false);
  manipulate(1, false);
  moveCenter(1500, 127, true);



}




#endif
