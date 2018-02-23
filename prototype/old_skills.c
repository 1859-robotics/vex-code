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
  moveCenter(-500);
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
  moveCenter(1300);
  // while(600 > fabs(EncoderGetValue(MANIPULATOR))) {}
  moveCenter(-200);
  SensorValue[GYRO_PORT] = 0;
  turn(90);
  moveCenter(325);
  manipulate(1, false, 800);
  SensorValue[GYRO_PORT] = 0;
  turn(45);
  moveCenter(1100);
  manipulate(-1, true); // pick up 4th MB
  moveCenter(-1500);
  turn(-45);
  moveCenter(-500);
  manipulator.canMove = false;
  turn(-90);
  manipulator.canMove = true;
  manipulate(1, false); // put 4th MB in 20pt zone
  moveCenter(500, 127, true);
  moveCenter(-500);
  turn(-90);
  moveCenter(500);
  turn(-95);
  moveCenter(500, 127, true);
  manipulate(-1, false); // pick up 5th MB
  while(1200 > fabs(EncoderGetValue(MANIPULATOR))) {}
  SensorValue[GYRO_PORT] = 0;
  turn(-180);
  manipulate(1, false); // put 5th MB in 10pt zone
  moveCenter(950);
  manipulate(-1, false, 600);
  moveCenter(-450);
  SensorValue[GYRO_PORT] = 0;
  turn(200);
  manipulate(1, false, 600);
  moveCenter(-200);
  moveCenter(700);
  manipulate(-1, false);
