#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

void resetEncoders() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  EncoderSetValue(R_MANIPULATOR, 0);

}

void auton22pt() {

  resetEncoders();

  manipulate(1);
  moveForward(1000);

  manipulate(-1);
  moveForward(-1000);

}


#endif
