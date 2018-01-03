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




//
// void skills() {
//
//   resetEncoders();
//
//   core(300, false);
//   manipulate(1, false);
//   moveCenter(600, 80, false);
//
//   turn(10, -40, true);
//   moveCenter(600, 80, true);
//
//   manipulate(-1, true); // pickup base
//   flip(-1, true);
//   claw(-120, true);
//   flip(1, true);
//   claw(80, false); // end of put cone on base
//
//   moveCenter(1200, -80, true);
//
//   turn(70, -40, true);
//   moveCenter(500, 40, true);
//   turn(80, -40, true);
//
//   moveCenter(750, 80, true);
//   manipulate(1, true);
//   moveCenter(410, -60, true); //pull out of scoring zone
//   manipulate(-1, true);
//
//   turn(90, -40, true);
//
//   flip(-1, true);
//
//   moveCenter(100, -40, true);
//   moveCenter(800, -80, true); //bot hits the wall
//   moveLeftEncoder(200, -80, true);
//   gyroZero();
//
//   moveCenter(250, 80, true);
//
//   flip(1, true);
//   manipulate(1, true);
//
//   turn(30, -40, true); // turn right before picking up the second base
//
//   moveCenter(450, 80, true);
//   manipulate(-1, true);
//
//   turn(200, -40, true); // turn before putting into scoring zone
//   moveCenter(1150, 80, true);
//
//   manipulate(1, true);
//   moveCenter(300, -80, false);
//
//   turn(175, 40, true);
//
//   moveCenter(100, 80, true);
//   manipulate(-1, true);
//   moveCenter(600, 80, true);
//
//
//
// }
//

void skills() {
  resetEncoders();
  wait1Msec(3000)
  core(300, true);
  manipulate(1, false);
  swerveRightGyro(50);
  moveCenter(960, 127, true);
  manipulate(-1, true);
  moveCenter(960, -100, true);
  turn(155);
  moveCenter(360, 127, true);
  manipulate(1, true);
  moveCenter(300, -127, true);
  writeDebugStream("end skills\n")
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
