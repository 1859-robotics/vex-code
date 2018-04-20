#ifndef _PROTOTYPE_AUTON_
#define _PROTOTYPE_AUTON_

#define LOADER_CORE 165
#define FIELD_CORE 0



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

/*************************************************************
 *                                                           *
 *      each of the following functions is an autonomas      *
 *                                                           *
 *************************************************************/

void auton20Long(int side) { // 3 cones on a MB in the 20 pt zone
  resetEncoders();
  //   core(100, false);
  // manipulate(1, false);
  // while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  // moveCenter(1300, 127, true);
  // manipulate(-1, true);
  //   core(-100, true);
  // claw(400, true);
  //   core(100, false);
  // flip(-1, true);
  //   core(-100, false);
  // claw(-700, true);
  //   core(100, true);
  // claw(-700, false);
  // flip(1, false);
  // moveCenter(-1500, false);
  // while(!FILP_UP_SWITCH) {}
  // claw(700, true);
  //   core(100, true);
  // flip(-1, false);
  //   core(-100, false);
  // turn(45 * side);
  // claw(-700, true);
  //   core(100, false);
  // flip(1, true);
  // claw(400, true);

}

void auton20Short(int side) { // 3 cones on a MB in the 20 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(400 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, false);
  while(500 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-650, 127, false);
  while(!manipulator.canMove) {}
  turn(45 * side, false);
  core(0, false);
  claw(400, true);

  core(LOADER_CORE + 25, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  claw(500, true);

  core(SensorValue(CORE_POTENTIOMETER) + 100, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, true);

  core(350, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  core(LOADER_CORE + 75, false);

  moveCenter(-700, false);
  flip(1, false);
  while(!drive.canMove) {}
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, false);

  turn(110 * side, true);
  core(400, false);
  moveCenter(1200, 100, false);
  while(500 > (fabs(EncoderGetValue(LB_DRIVE)) + fabs(EncoderGetValue(RB_DRIVE))) / 2) {}
  manipulate(1, false, 800);
  moveCenter(-700, 80, true);

}

void auton20(int side) { // 2 cones on a MB in the 20 pt zone
  resetEncoders();

  core(20, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500, true);
  manipulate(-1, true);
  moveCenter(175, false);
  core(FIELD_CORE, true);
  claw(400, true);
  core(20, false);
  flip(-1, true);
  core(FIELD_CORE, false);
  claw(-1000, true);
  core(20, true);
  claw(-700, false);
  flip(1, false);
  moveCenter(-1700, false);
  while(!SensorValue(FILP_UP_SWITCH)) {}
  core(20, false);
  claw(1000, true);
  core(50, false);
  turn(-135 * side);
  moveCenter(550, true);
  turn(-90 * side);
  manipulate(1, false, 800);
  moveCenter(650, 80, true);
  moveCenter(-600, true);


}



void auton5long(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500, true);
  manipulate(-1, true);
  moveCenter(175, false);
  core(FIELD_CORE, true);
  claw(400, true);
  core(100, false);
  flip(-1, true);
  core(FIELD_CORE, false);
  claw(-1000, true);
  core(100, true);
  claw(-700, false);
  flip(1, false);
  moveCenter(-1400, false);
  while(!SensorValue(FILP_UP_SWITCH)) {}
  core(20, false);
  claw(1000, true);
  core(120, false);
  turn(-180 * side);
  manipulate(1, true);
  moveCenter(-600, true);

}

void auton5Short(int side) { // 5 cones on a MB in the 5 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(400 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, false);
  while(500 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-700, 127, false);
  while(!manipulator.canMove) {}
  turn(45 * side, false);
  core(0, false);
  claw(400, true);

  core(LOADER_CORE + 25, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  claw(500, true);

  core(SensorValue(CORE_POTENTIOMETER) + 100, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, true);

  core(350, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  core(LOADER_CORE + 75, false);
  flip(1, true);
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, true);

  core(500, false);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  core(LOADER_CORE + 100, false);
  turn(90 * side, false);
  flip(1, true);
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, true);

  core(SensorValue(CORE_POTENTIOMETER) + 200, false);
  manipulate(1, false);
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  driveF(-127);
}




void auton10long(int side) { // 4 cones on a MB in the 10 pt zone
  resetEncoders();


}

void auton10Short(int side) { // 4 cones on a MB in the 10 pt zone
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  while(400 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1300, 127, true);
  manipulate(-1, false);
  while(500 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-650, 127, false);
  while(!manipulator.canMove) {}
  turn(45 * side, false);
  core(0, false);
  claw(400, true);

  core(LOADER_CORE + 25, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  claw(500, true);

  core(SensorValue(CORE_POTENTIOMETER) + 100, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  flip(1, true);
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, true);

  core(350, true);
  flip(-1, true);
  core(LOADER_CORE, false);
  claw(-400, true);
  core(LOADER_CORE + 75, false);

  moveCenter(-400, false);
  flip(1, false);
  while(!drive.canMove) {}
  core(SensorValue(CORE_POTENTIOMETER) - 100, false);
  claw(500, false);

  turn(110 * side, true);
  core(400, false);
  moveCenter(770, 127, true);
  manipulate(1, true);
  moveCenter(-700, 80, true);
}

void autonStatLong(int side) { // 2 cones on the stationary goal + tip a MB
  resetEncoders();

}

void autonStatShort(int side) { // 2 cones on the stationary goal + tip a MB
  resetEncoders();

}

void autonSabatoge(int side) {
  resetEncoders();
  manipulate(1, false);
  while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(400);
  turn(45 * side);
  driveF(127);
  wait1Msec(2500);
  driveF(0);
}




/******************************************************************************/







void skills() {
  resetEncoders();

  core(50, false);
  manipulate(1, false);
  while(400 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(1500);
  manipulate(-1, true); // pick up MB
  moveCenter(-1400);
  SensorValue[GYRO_PORT] = 0;
  turn(-135);
  moveCenter(650);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false); // put 1st MB in 20pt zone

  moveCenter(500, 127, true);
  moveCenter(-650);
  SensorValue[GYRO_PORT] = 0;
  turn(-90);
  moveCenter(450);
  turn(-90);
  moveCenter(650);
  core(100, false);
  manipulate(-1, true); // pick up 2nd MB
  core(0, true);
  claw(600, false);
  turn(180, true)
  moveCenter(950);
  manipulate(1, true); // put 2nd MB in 10pt zone
  moveCenter(-400);
  SensorValue[GYRO_PORT] = 0;
  turn(-180, true)
  moveCenter(1400);
  manipulate(-1, true);
  moveCenter(1000);
  SensorValue[GYRO_PORT] = 0;
  turn(-90);
  moveCenter(600);
  turn(90);
  manipulate(1, false);
  moveCenter(500, 127, true);
  moveCenter(-650);
  // SensorValue[GYRO_PORT] = 0;
  // turn(-90);
  // moveCenter(500, true);
}

#endif
