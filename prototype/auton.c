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

void autonRight22() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  swerveLeftGyro(-48);
  moveCenter(850, 127, true);
  moveCenter(270, 40, true);
  manipulate(-1, true); // pick up MB
  moveCenter(30, 40, true);
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(650, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(720, -127, false);
  claw(-300, true); // pick up next cone
  while(!drive.canMove) {}
  core(-100, true);
  claw(500, true); // put next cone on base
  core(200, false);
  swerveRightGyro(-48);
  moveCenter(300, -127, true);
  manipulator.canMove = false
  turn(-90);
  manipulator.canMove = true
  manipulate(1, false);
  moveCenter(600, 100, true);
  moveCenter(500, -127, true);
  manipulate(-1, true);

  writeDebugStream("end \n")
}

void autonRight9() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  swerveLeftGyro(-48);
  moveCenter(850, 127, true);
  moveCenter(270, 40, true);
  manipulate(-1, true); // pick up MB
  moveCenter(30, 40, true);
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(650, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(720, -127, false);
  claw(-300, true); // pick up next cone
  while(!drive.canMove) {}
  core(-100, true);
  claw(500, true); // put next cone on base
  core(200, false);
  turn(160)
  manipulate(1, true); // pick up MB
  moveCenter(220, -127, true);
  manipulate(-1, true);


  writeDebugStream("end \n")
}

void autonLeft9() {
  resetEncoders();
  core(100, false);
  manipulate(1, true);
  swerveRightGyro(48);
  moveCenter(850, 127, true);
  moveCenter(300, 40, true);
  manipulate(-1, true); // pick up MB
  moveCenter(30, 40, true);
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(650, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(720, -127, false);
  claw(-300, true); // pick up next cone
  while(!drive.canMove) {}
  core(-100, true);
  claw(500, true); // put next cone on base
  core(200, false);
  turn(-160)
  manipulate(1, true); // pick up MB
  moveCenter(220, -127, true);
  manipulate(-1, true);

}

void autonLeft22() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  swerveRightGyro(48);
  moveCenter(850, 127, true);
  moveCenter(270, 40, true);
  manipulate(-1, true); // pick up MB
  moveCenter(30, 40, true);
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(650, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(720, -127, false);
  claw(-300, true); // pick up next cone
  while(!drive.canMove) {}
  core(-100, true);
  claw(500, true); // put next cone on base
  core(200, false);
  swerveLeftGyro(-48);
  moveCenter(300, -127, true);
  manipulator.canMove = false
  turn(90);
  manipulator.canMove = true
  manipulate(1, false);
  moveCenter(600, 100, true);
  moveCenter(500, -127, true);
  manipulate(-1, true);

  writeDebugStream("end \n")
}
#endif
