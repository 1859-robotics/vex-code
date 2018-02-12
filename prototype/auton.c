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
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 100, true);
  moveCenter(500, -127, true);
  manipulate(-1, true);

  writeDebugStream("end \n");
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
  turn(160);
  manipulate(1, true); // pick up MB
  moveCenter(220, -127, true);
  manipulate(-1, true);


  writeDebugStream("end \n");
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
  turn(-160);
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
  manipulator.canMove = false;
  turn(90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 100, true);
  moveCenter(500, -127, true);
  manipulate(-1, true);

  writeDebugStream("end \n");
}

void skills() {
  resetEncoders();
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  wait1Msec(500);
  moveCenter(1500);
  manipulate(-1, true); // pick up MB
  core(-100, false);
  moveCenter(-1500);
  claw(500, false); // put cone on base
  turn(50);
  core(100, false);
  moveCenter(-500);
  manipulator.canMove = false;
  turn(95);
  manipulator.canMove = true;
  manipulate(1, false); // put 1st MB in 2pt zone
  moveCenter(500, 127, true);
  moveCenter(-400);
  turn(-90);
  moveCenter(450);
  turn(-95);
  moveCenter(650, 127, true);
  manipulate(-1, true); // pick up 2nd MB
  moveCenter(-900);
  SensorValue[GYRO_PORT] = 0;
  turn(190);
  manipulate(1, false); // put 2nd MB in 10pt zone
  moveCenter(300);
  turn(5);
  moveCenter(-1050);
  SensorValue[GYRO_PORT] = 0;
  turn(95);
  moveCenter(1000);
  manipulate(-1, true); // pick up 3rd MB
  turn(-95);
  moveCenter(700);
  manipulate(1, false); // put 3rd MB in 10pt zone
  moveCenter(400);
  moveCenter(-300);
  turn(190);
  moveCenter(1300);
  manipulate(-1, false); // pick up 4th MB
  moveCenter(1300);
  turn(3);
  manipulate(1, true); // put 4th MB in 10pt zone
  moveCenter(-300);

}

void auton6Stat() {
  PID slow;
  pidInit(slow, 2, 0, 0.15, 2, 20.0, MIN_SPEED, 80);
  resetEncoders();
  core(400, false);
  moveCenter(60, 60, true);
  swerveRightGyro(43);
  moveCenter(40, 60, false);
  flip(550, -1, true);
  core(-100, true);
  claw(500, true); // put preload on stationary goal
  core(150, true);
  flip(550, 1, true);
  turn(-86, slow); // turn to face 2nd cone
  moveCenter(60, 40, true);
  flip(550, -1, true);
  core(-500, true);
  claw(-750, true); // pick up 2nd cone
  flip(550, 1, true);
  moveCenter(60, -40, true);
  claw(-750, false);
  core(500, true);
  turn(90, slow);
  moveCenter(80, 60, true);
  flip(550, -1, true);
  claw(500, true); // put 2nd cone on stationary goal
  core(100, false);
  flip(550, 1, true);



  // core(400, false);
  // moveCenter(60, 60, true)
  // swerveRightGyro(48);
  // moveCenter(300, 127, true)
  // core(-100, true);
  // claw(500, true);
  // core(100, false);
  // moveCenter(200, -60, true)
  // core(-200, false);
  // flip(650, -1, false);
  // turn(-90);
  // moveCenter(60, 60, true)
  // core(-200, false);
  // claw(-500, true);
  // flip(650, 1, false);

}

// void autonDualStack() {
//   resetEncoders();
//   core(400, false);
//   moveCenter(100, 100, true);
//   moveCenter(40, 100, false);
//   flip(550, -1, true);
//   core(-100, true);
//   claw(500, true); // put preload on stationary goal
//   core(150, true);
//   manipulate(1, false);
//   flip(550, 1, false);
//   moveCenter(350, -100, true);
//   turn(-90) // turn to lane of cones
//   core(-500, false);
//   moveCenter(900, 127, true);
//   moveCenter(300, 60, true);
//   manipulate(-1, true);
//   flip(550, -1, true);
//   claw(-750, true); // pick up next cone
//   core(100, true);
//   flip(550, 1, true);
//   drive.canMove = true;
//   moveCenter(720, -127, false);
//   claw(-300, true); // pick up next cone
//   while(!drive.canMove) {}
//   core(-100, true);
//   claw(500, true); // put next cone on base
//   core(200, false);
//   turn(180);
//   manipulate(1, true);
//   moveCenter(300, -127, false);
//
// }

#endif
