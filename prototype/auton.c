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
  moveCenter(1500);
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
  moveCenter(350, -127, true);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 80, true);
  moveCenter(500, -100, true);
  manipulate(-1, true);

  writeDebugStream("end \n");
}

void autonRight9() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  wait1Msec(500);
  moveCenter(1400);
  manipulate(-1, false); // pick up MB
  moveCenter(160);
  drive.canMove = false;
  while(!manipulator.canMove) {}
  core(-120, true);
  claw(600, true); // put cone on MB
  flip(650, -1, true);
  claw(-600, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  claw(600, false); // put cone on MB
  moveCenter(350);
  flip(650, -1, true);
  core(-100, true);
  claw(-600, true); // pick up next cone
  core(200, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(-1500);
  // claw(-300, false); // pick up next cone
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, true); // put next cone on base
  core(200, false);
  manipulate(1, false); // pick up MB
  turn(-110);
  moveCenter(220, -127, true);
  manipulate(-1, true);


  writeDebugStream("end \n");
}

void autonLeft9() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  wait1Msec(500);
  moveCenter(1400);
  manipulate(-1, false); // pick up MB
  moveCenter(160);
  drive.canMove = false;
  while(!manipulator.canMove) {}
  core(-120, true);
  claw(600, true); // put cone on MB
  flip(650, -1, true);
  claw(-600, true); // pick up next cone
  core(100, true);
  flip(650, 1, true);
  claw(600, false); // put cone on MB
  moveCenter(370);
  flip(650, -1, true);
  core(-100, true);
  claw(-600, true); // pick up next cone
  core(200, true);
  flip(650, 1, true);
  drive.canMove = true;
  moveCenter(-1500);
  // claw(-300, false); // pick up next cone
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, true); // put next cone on base
  core(200, false);
  manipulate(1, false); // pick up MB
  turn(110);
  moveCenter(220, -127, true);
  manipulate(-1, true);


}

void autonLeft22() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  wait1Msec(200);
  moveCenter(1500);
  manipulate(-1, true); // pick up MB
  moveCenter(90, 40, true);
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
  swerveLeftGyro(48);
  moveCenter(350, -127, true);
  manipulator.canMove = false;
  turn(90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 80, true);
  moveCenter(500, -100, true);
  manipulate(-1, true);

  writeDebugStream("end \n");
}

void skills() {
  resetEncoders();

  core(100, false);
  manipulate(1, false);
  wait1Msec(500);
  moveCenter(1500);
  manipulate(-1, true); // pick up MB
  moveCenter(-1400);
  core(-100, false);
  claw(500, false); // put cone on base
  turn(50);
  core(100, false);
  moveCenter(-400);
  manipulator.canMove = false;
  turn(100);
  manipulator.canMove = true;
  manipulate(1, false); // put 1st MB in 20pt zone
  moveCenter(500, 127, true);
  moveCenter(-600);
  turn(-170);
  moveCenter(600);
  manipulate(-1, false); // pick up 2nd MB
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  turn(170);
  manipulate(1, false); // put 2nd MB in 10pt zone
  moveCenter(850);
  manipulate(-1, false, 600);
  moveCenter(-950);
  SensorValue[GYRO_PORT] = 0;
  turn(185);
  manipulate(1, false, 600);
  moveCenter(-200);
  moveCenter(1100);
  manipulate(-1, false, 800); // pick up 3rd MB
  moveCenter(1300, 127, true);
  // while(600 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-200);
  SensorValue[GYRO_PORT] = 0;
  turn(90);
  moveCenter(300);
  manipulate(1, false, 800);
  SensorValue[GYRO_PORT] = 0;
  turn(45);
  moveCenter(1100);
  manipulate(-1, true); // pick up 4th MB
  moveCenter(-1500);
  turn(-45);
  moveCenter(-750);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false); // put 4th MB in 20pt zone
  moveCenter(500, 127, true);
  moveCenter(-600);
  turn(-170);
  moveCenter(600, 127, true);
  manipulate(-1, false); // pick up 5th MB
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  SensorValue[GYRO_PORT] = 0;
  turn(-180);
  moveCenter(500);
  manipulate(1, false); // put 5th MB in 10pt zone
  moveCenter(500, 127, true);
  manipulate(-1, false);
  moveCenter(-450);
  SensorValue[GYRO_PORT] = 0;
  turn(183);
  manipulate(1, false);
  moveCenter(-200);
  moveCenter(1300);
  manipulate(-1, false, 600);
  moveCenter(1600);
  manipulate(1, false, 600);
  moveCenter(-300);
}

void auton6Stat() {
  PID slow;
  pidInit(slow, 2, 0, 0.15, 2, 20.0, MIN_SPEED, 80);
  resetEncoders();
  core(400, false);
  moveCenter(400);
  flip(550, -1, true);
  core(-100, true);
  claw(500, true); // put preload on stationary goal
  core(150, true);
  flip(550, 1, true);
  turn(-90, slow); // turn to face 2nd cone
  flip(550, -1, true);
  core(-500, true);
  claw(-750, true); // pick up 2nd cone
  flip(550, 1, true);
  // moveCenter(60, -40, true);
  // claw(-750, false);
  // core(500, true);
  // turn(90, slow);
  // moveCenter(80, 60, true);
  // flip(550, -1, true);
  // claw(500, true); // put 2nd cone on stationary goal
  // core(100, false);
  // flip(550, 1, true);



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
