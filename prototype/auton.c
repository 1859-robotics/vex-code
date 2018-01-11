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


void skills() {
  resetEncoders();


  // wait1Msec(3000)
  core(300, true);
  manipulate(1, false);
  swerveRightGyro(50);
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

// void auton7ptRight() {
//
//   resetEncoders();
//
// }
//
// void auton22ptLeft() {
//
//   resetEncoders();
//
//   core(200, true);
//   manipulate(1, false);
//   // moveLeftGyro(50, 40, true);
//
//   moveCenter(50, 80, true)
//   turn(45, -40, true);
//   moveCenter(1400, 127, true);
//
//
//   manipulate(-1, true); // pick up mobile base
//   core(-100, true);
//   claw(-80, true); // put cone on base
//
//   // core(100, true);
//   // flip(300, 1, true);
//   // core(-100, true);
//   // claw(80, true);
//   // core(100, true);
//   // flip(300, -1, true);
//   // core(-100, true);
//   // claw(-80, false); // put cone on base
//
//   moveCenter(900, -80, true);
//
//   turn(250, 80, true);
//
//   core(200, true);
//
//   manipulate(1, true);
//
//   moveCenter(250, -80, false);
//
//   manipulate(-1, false);
// >>>>>>> df9f98f4aba2f86939d2b472a41ce868f6c99326
//
// }
//
// void auton7ptLeft() {
//
//     resetEncoders();
//
//     core(200, true);
//     manipulate(1, false);
//     // moveLeftGyro(50, 40, true);
//
// <<<<<<< HEAD
// =======
//     moveCenter(50, 80, true)
//     turn(45, 40, true);
//     moveCenter(1400, 127, true);
//
//
//     manipulate(-1, true); // pick up mobile base
//     core(-100, true);
//     claw(-80, true); // put cone on base
//
//     // core(100, true);
//     // flip(300, 1, true);
//     // core(-100, true);
//     // claw(80, true);
//     // core(100, true);
//     // flip(300, -1, true);
//     // core(-100, true);
//     // claw(-80, false); // put cone on base
//
//     moveCenter(900, -80, true);
//
//     turn(180, -80, true);
//
//     core(200, true);
//
//     manipulate(1, true);
//
//     moveCenter(250, -80, false);
//
//     manipulate(-1, false);
// >>>>>>> df9f98f4aba2f86939d2b472a41ce868f6c99326
// }
//



#endif
