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
  moveCenter(500);
  manipulator.canMove = false;
  turn(-80);
  manipulator.canMove = true;
  manipulate(1, false); // put 1st MB in 20pt zone
  moveCenter(500, 127, true);
  moveCenter(-600);
  SensorValue[GYRO_PORT] = 0;
  turn(-170);
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
  moveCenter(350);
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
  turn(-115);
  driveF(127)
}
