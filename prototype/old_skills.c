void skills() {
  PID fast;
  pidInit(fast, 2, 0, 0.15, 2, 20.0, 80, 127);
  resetEncoders();
  core(100, false);
  manipulate(1, false);
  swerveLeftGyro(-50);
  moveCenter(850, 127, true);
  moveCenter(270, 40, true);
  manipulate(-1, true); // pick up MB
  core(-100, false);
  claw(500, true); // put cone on base
  core(100, false);
  moveCenter(1200, -127, true);
  swerveRightGyro(-50, fast);
  moveCenter(50, -60, true);
  turn(-90);
  moveCenter(50, 60, false);
  manipulate(1, true); // put MB in 10pt zone
  moveCenter(100, -127, true);
  core(-100, false);
  turn(185);
  moveCenter(300, 127, true);
  manipulate(-1, true); // pick up 2nd MB
  moveCenter(650, -127, true);
  turn(-90);
  moveCenter(350, -127, true);
  turn(-90);
  moveCenter(500, 127, false);
  manipulate(1, true); // put MB in 20pt zone
  moveCenter(400, -127, true);

  driveF(40)
  wait1Msec(500)

  moveCenter(200, -60, true);
  turn(-90);
  moveCenter(300, 127, true);
  SensorValue[GYRO_PORT] = 0;
  turn(-90);
  moveCenter(650, 127, true);
  manipulate(-1, true); // pick up 3rd MB
  moveCenter(600, -127, true);
  SensorValue[GYRO_PORT] = 0;
  turn(-190);
  moveCenter(200, 127, false);
  manipulate(1, true); // put 3rd MB in 10pt zone
  moveCenter(200, -127, true);
  SensorValue[GYRO_PORT] = 0;
  turn(-180);
  moveCenter(1400, 127, true);
  manipulate(-1, false); // pick up 4th MB
  moveCenter(650, 127, true);
  SensorValue[GYRO_PORT] = 0;
  while(manipulator.canMove) {}
  turn(-90);
  moveCenter(400, 127, true);
  SensorValue[GYRO_PORT] = 0;
  turn(90);

}
