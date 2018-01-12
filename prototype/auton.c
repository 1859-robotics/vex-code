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


void autonRight12() {

  swerveLeftGyro(-40);
  writeDebugStream("end first\n");
  swerveLeftGyro(40);
  writeDebugStream("end 2nd\n");

  // resetEncoders();
  // core(300, true);
  // manipulate(1, false);
  // swerveRightGyro(50);
  // moveCenter(1000, 127, true);
  // manipulate(-1, true); // pick up MB
  // core(-300, true);
  // claw(-10, true); // put cone on base
  // core(300, true);
  // moveCenter(100, -60, true);
  // moveCenter(900, -127, true);
  // // swerveLeftGyro(-40);
  // turn(45);
  // moveCenter(250, -127, true);
  // turn(90);
  // moveCenter(100, 127, true);
  // // turn(20);
  // manipulate(1, true);
  // moveCenter(350, -127, true); // back out of putting MB in 10pt zone
  // // turn(180);
  // // moveCenter(360, 127, true);
  // // writeDebugStream("end \n")

}



void autonLeft12() {
  resetEncoders();
  core(300, true);
  manipulate(1, false);
  swerveLeftGyro(50);
  moveCenter(1000, 127, true);
  manipulate(-1, true); // pick up MB
  core(-300, true);
  claw(-10, true); // put cone on base
  core(300, true);
  moveCenter(100, -60, true);
  moveCenter(900, -127, true);
  // swerveLeftGyro(-40);
  turn(45);
  moveCenter(250, -127, true);
  turn(90);
  moveCenter(100, 127, true);
  // turn(20);
  manipulate(1, true);
  moveCenter(350, -127, true); // back out of putting MB in 10pt zone
  // turn(180);
  // moveCenter(360, 127, true);
  // writeDebugStream("end \n")

}


#endif
