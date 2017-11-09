#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

void resetEncoders() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  EncoderSetValue(R_MANIPULATOR, 0);

  EncoderSetValue(FLIP_LIFT, 0);
  EncoderSetValue(L_CORE_LIFT, 0);
  EncoderSetValue(LIFT_CLAW, 0);

}

void auton22pt() {

  resetEncoders();

  core(300, false);
  manipulate(1, false);
  moveForward(1500, true);

  manipulate(-1, true);
  moveForward(-1600, true);

  turn(175, true);
  moveForward(170, true);
  turn(175, true);

  moveForward(500, true);


}


#endif
