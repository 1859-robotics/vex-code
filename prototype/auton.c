#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

#define FLIP_AMT 400

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
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500);
  manipulate(-1, false); // pick up MB
  moveCenter(200);
  while(!manipulator.canMove) {}
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(FLIP_AMT, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  drive.canMove = true;
  claw(-300, false); // pick up next cone
  moveCenter(-1500);
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, false); // put next cone on base
  turn(135);
  core(200, false);
  moveCenter(600);
  manipulator.canMove = false;
  turn(90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 127, true);
  moveCenter(-500);

  writeDebugStream("end \n");
}

void autonRight9() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500);
  manipulate(-1, false); // pick up MB
  moveCenter(200);
  while(!manipulator.canMove) {}
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(FLIP_AMT, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  drive.canMove = true;
  claw(-300, false); // pick up next cone
  moveCenter(-1500);
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, false); // put next cone on base
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, true); // put next cone on base
  core(200, false);
  manipulate(1, false); // pick up MB
  turn(-110);
  moveCenter(220, -127, true);


  writeDebugStream("end \n");
}

void autonRight11() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1400);
  manipulate(-1, false); // pick up MB
  moveCenter(250);
  drive.canMove = false;
  while(!manipulator.canMove) {}
  core(-120, true);
  claw(600, true); // put cone on MB
  flip(FLIP_AMT, -1, true);
  claw(-600, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  claw(600, false); // put cone on MB
  moveCenter(225);
  flip(FLIP_AMT, -1, true);
  core(-100, true);
  claw(-600, true); // pick up next cone
  core(200, true);
  flip(FLIP_AMT, 1, true);
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


  writeDebugStream("end \n");
}

void autonLeft11() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1400);
  manipulate(-1, false); // pick up MB
  moveCenter(200);
  drive.canMove = false;
  while(!manipulator.canMove) {}
  core(-120, true);
  claw(600, true); // put cone on MB
  flip(FLIP_AMT, -1, true);
  claw(-700, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  claw(600, false); // put cone on MB
  moveCenter(370);
  flip(FLIP_AMT, -1, true);
  core(-100, true);
  claw(-600, true); // pick up next cone
  core(200, true);
  flip(FLIP_AMT, 1, true);
  drive.canMove = true;
  claw(-600, false);
  moveCenter(-1500);
  // claw(-300, false); // pick up next cone
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, true); // put next cone on base
  core(200, false);
  manipulate(1, false); // pick up MB
  turn(110);
  moveCenter(220, -127, true);


}

void autonLeft9() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500);
  manipulate(-1, false); // pick up MB
  moveCenter(200);
  while(!manipulator.canMove) {}
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(FLIP_AMT, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  drive.canMove = true;
  claw(-300, false); // pick up next cone
  moveCenter(-1500);
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, false); // put next cone on base
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, true); // put next cone on base
  core(200, false);
  manipulate(1, false); // pick up MB
  turn(110);
  moveCenter(220, -127, true);

  writeDebugStream("end \n");

}

void autonLeft22() {
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500);
  manipulate(-1, false); // pick up MB
  moveCenter(200);
  while(!manipulator.canMove) {}
  drive.canMove = false;
  core(-100, true);
  claw(500, true); // put cone on base
  flip(FLIP_AMT, -1, true);
  claw(-750, true); // pick up next cone
  core(100, true);
  flip(FLIP_AMT, 1, true);
  drive.canMove = true;
  claw(-300, false); // pick up next cone
  moveCenter(-1500);
  while(!drive.canMove) {}
  core(-100, false);
  claw(500, false); // put next cone on base
  turn(-135);
  core(200, false);
  moveCenter(600);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false);
  moveCenter(600, 127, true);
  moveCenter(-500);

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

  SensorValue[GYRO_PORT] = 0;
  turn(-135);
  moveCenter(400);
  manipulator.canMove = false;
  turn(-80);
  manipulator.canMove = true;
  manipulate(1, false); // put 1st MB in 20pt zone
  moveCenter(500, 127, true);
  moveCenter(-600);
  SensorValue[GYRO_PORT] = 0;
  turn(-175);
  moveCenter(700);
  core(100, false);
  manipulate(-1, false); // pick up 2nd MB
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  core(-150, false);
  claw(500, false); // put cone on base
  turn(170);
  core(100, false);
  manipulate(1, false); // put 2nd MB in 10pt zone
  moveCenter(850);
  manipulate(-1, false, 600);
  moveCenter(-850);
  SensorValue[GYRO_PORT] = 0;
  turn(185);
  manipulate(1, false, 600);
  moveCenter(-200);
  moveCenter(1100);
  manipulate(-1, false, 800); // pick up 3rd MB
  moveCenter(1350, 127, true);
  // while(600 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-150);
  SensorValue[GYRO_PORT] = 0;
  turn(90);
  moveCenter(175);
  manipulate(1, false, 800);
  SensorValue[GYRO_PORT] = 0;
  turn(47);
  moveCenter(1250);
  manipulate(-1, true); // pick up 4th MB
  moveCenter(-1200);
  turn(-45);
  moveCenter(-800);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false); // put 4th MB in 20pt zone
  moveCenter(600, 127, true);
  moveCenter(-600);
  // turn(-160);
  turn(-90);
  moveCenter(300);
  turn(-90);
  moveCenter(700, 127, true);
  manipulate(-1, false); // pick up 5th MB
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  SensorValue[GYRO_PORT] = 0;
  turn(-185);
  manipulate(1, false, 400); // put 5th MB in 10pt zone
  moveCenter(1200, 127, true);
  moveCenter(-450);
  SensorValue[GYRO_PORT] = 0;
  turn(-185);
  manipulate(1, false, 1200);
  moveCenter(-200);
  moveCenter(1600);
  manipulate(-1, false, 600); // pick up 6th MB
  moveCenter(1600, 127, true);
  manipulate(1, false, 600);
  moveCenter(-300);
  turn(115);
  driveF(127)
}

void auton6Stat() {
  resetEncoders();
  core(400, false);
  moveCenter(400);
  flip(550, -1, true);
  core(-100, true);
  claw(500, true); // put preload on stationary goal
  core(150, true);
  flip(550, 1, true);
  turn(-90); // turn to face 2nd cone
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
  // flip(FLIP_AMT, -1, false);
  // turn(-90);
  // moveCenter(60, 60, true)
  // core(-200, false);
  // claw(-500, true);
  // flip(FLIP_AMT, 1, false);

}

void sabatoge() {
  resetEncoders();
  // manipulate(1, false);
  // while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  // moveCenter(400)
  // turn(-45)
  // moveCenter(1000)
  moveCenter(800)
  flip(350, -1, true);
  claw(-500, true)
  moveCenter(-600)

}

#endif
