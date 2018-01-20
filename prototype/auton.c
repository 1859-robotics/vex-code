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


void autonLeft12() {
  resetEncoders();
  core(300, true);
  swerveRightGyro(50);
  moveCenter(50, -60, true);
  manipulate(1, true);
  moveCenter(1500, 127, true);
  manipulate(-1, true); // pick up MB
  core(-300, true);
  claw(-10, true); // put cone on base
  core(300, true);
  moveCenter(100, -60, true);
  moveCenter(1100, -127, true);
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



void autonRight12() {
  resetEncoders();
  core(300, true);
  swerveLeftGyro(-50);
  moveCenter(50, -60, true);
  manipulate(1, true);
  moveCenter(1500, 127, true);
  manipulate(-1, true); // pick up MB
  core(-300, true);
  claw(-10, true); // put cone on base
  core(300, true);
  moveCenter(100, -60, true);
  moveCenter(1100, -127, true);
  // swerveLeftGyro(-40);
  turn(-45);
  moveCenter(250, -127, true);
  turn(-90);
  moveCenter(100, 127, true);
  // turn(20);
  manipulate(1, true);
  moveCenter(350, -127, true); // back out of putting MB in 10pt zone


  writeDebugStream("end \n")
}

void skills() {
  resetEncoders();
  core(300, true);
  swerveRightGyro(50);
  moveCenter(50, -60, true);
  manipulate(1, true);
  moveCenter(1300, 127, true);
  manipulate(-1, true); // pick up MB
  core(-200, true);
  claw(-10, true); // put cone on base
  core(300, true);
  moveCenter(100, -60, true);
  moveCenter(1000, -127, true);
  // swerveLeftGyro(-40);
  turn(45);
  moveCenter(250, -127, true);
  turn(90);
  moveCenter(120, 127, true);
  // turn(20);
  manipulate(1, true);
  moveCenter(170, -127, true); // back out of putting MB in 10pt zone
  turn(-180);
  moveCenter(400, 127, true);
  manipulate(-1, true); // pick up 2nd moba
  moveCenter(500, -100, true);
  turn(90);
  moveCenter(380, -100, true);
  turn(105);
  moveCenter(650, 127, true);
  manipulate(1, true); // put MB in 20pt zone
  moveCenter(500, -127, true);
  turn(90);
  moveCenter(320, 127, true);
  turn(90);
  moveCenter(320, 127, true);
  manipulate(-1, true);

}


#endif
