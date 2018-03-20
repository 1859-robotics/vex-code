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

/*************************************************************
 *                                                           *
 *      each of the following functions is an autonomas      *
 *                                                           *
 *************************************************************/

// void autonRight22() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1500);
//   manipulate(-1, false); // pick up MB
//   moveCenter(200);
//   while(!manipulator.canMove) {}
//   drive.canMove = false;
//   core(-100, true);
//   claw(500, true); // put cone on base
//   flip(FLIP_AMT, -1, true);
//   claw(-750, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   claw(-300, false); // pick up next cone
//   moveCenter(-1500);
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, false); // put next cone on base
//   turn(135);
//   core(200, false);
//   moveCenter(600);
//   manipulator.canMove = false;
//   turn(90);
//   manipulator.canMove = true;
//   manipulate(1, false);
//   moveCenter(600, 100, true);
//   moveCenter(-500);
//
//   writeDebugStream("end \n");
// }
//
// void autonRight9() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1500);
//   manipulate(-1, false); // pick up MB
//   moveCenter(200);
//   while(!manipulator.canMove) {}
//   drive.canMove = false;
//   core(-100, true);
//   claw(500, true); // put cone on base
//   flip(FLIP_AMT, -1, true);
//   claw(-750, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   claw(-300, false); // pick up next cone
//   moveCenter(-1500);
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, false); // put next cone on base
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, true); // put next cone on base
//   core(200, false);
//   manipulate(1, false); // pick up MB
//   turn(-110);
//   moveCenter(220, -127, true);
//
//
//   writeDebugStream("end \n");
// }
//
// void autonRight11() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1400);
//   manipulate(-1, false); // pick up MB
//   moveCenter(250);
//   drive.canMove = false;
//   while(!manipulator.canMove) {}
//   core(-120, true);
//   claw(600, true); // put cone on MB
//   flip(FLIP_AMT, -1, true);
//   claw(-600, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   claw(600, false); // put cone on MB
//   moveCenter(225);
//   flip(FLIP_AMT, -1, true);
//   core(-100, true);
//   claw(-600, true); // pick up next cone
//   core(200, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   moveCenter(-1500);
//   // claw(-300, false); // pick up next cone
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, true); // put next cone on base
//   core(200, false);
//   manipulate(1, false); // pick up MB
//   turn(-110);
//   moveCenter(220, -127, true);
//
//
//   writeDebugStream("end \n");
// }
//
// void autonLeft11() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1400);
//   manipulate(-1, false); // pick up MB
//   moveCenter(200);
//   drive.canMove = false;
//   while(!manipulator.canMove) {}
//   core(-120, true);
//   claw(600, true); // put cone on MB
//   flip(FLIP_AMT, -1, true);
//   claw(-700, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   claw(600, false); // put cone on MB
//   moveCenter(370);
//   flip(FLIP_AMT, -1, true);
//   core(-100, true);
//   claw(-600, true); // pick up next cone
//   core(200, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   claw(-600, false);
//   moveCenter(-1500);
//   // claw(-300, false); // pick up next cone
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, true); // put next cone on base
//   core(200, false);
//   manipulate(1, false); // pick up MB
//   turn(110);
//   moveCenter(220, -127, true);
//
//
// }
//
// void autonLeft9() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1500);
//   manipulate(-1, false); // pick up MB
//   moveCenter(200);
//   while(!manipulator.canMove) {}
//   drive.canMove = false;
//   core(-100, true);
//   claw(500, true); // put cone on base
//   flip(FLIP_AMT, -1, true);
//   claw(-750, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   claw(-300, false); // pick up next cone
//   moveCenter(-1500);
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, false); // put next cone on base
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, true); // put next cone on base
//   core(200, false);
//   manipulate(1, false); // pick up MB
//   turn(110);
//   moveCenter(220, -127, true);
//
//   writeDebugStream("end \n");
//
// }
//
// void autonLeft22() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1500);
//   manipulate(-1, false); // pick up MB
//   moveCenter(200);
//   while(!manipulator.canMove) {}
//   drive.canMove = false;
//   core(-100, true);
//   claw(500, true); // put cone on base
//   flip(FLIP_AMT, -1, true);
//   claw(-750, true); // pick up next cone
//   core(100, true);
//   flip(FLIP_AMT, 1, true);
//   drive.canMove = true;
//   claw(-300, false); // pick up next cone
//   moveCenter(-1500);
//   while(!drive.canMove) {}
//   core(-100, false);
//   claw(500, false); // put next cone on base
//   turn(-135);
//   core(200, false);
//   moveCenter(600);
//   manipulator.canMove = false;
//   turn(-90);
//   manipulator.canMove = true;
//   manipulate(1, false);
//   moveCenter(600, 100, true);
//   moveCenter(-500);
//
//   writeDebugStream("end \n");
// }
//
// void skills() {
//   resetEncoders();
//   core(100, false);
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(1000);
//   manipulate(-1, true);
//   core(-100, false);
//   turn(190)
//   claw(500, true)
//   core(100, false);
//   moveCenter(900);
//   manipulate(1, true);
//   core(-100, false);
//   moveCenter(-400);
//   turn(-185)
//   moveCenter(1500);
//   manipulate(-1, true);
//   moveCenter(1300);
//   manipulate(1, true);
//   moveCenter(-1300);
//   manipulate(-1, true, 800);
//   turn(-90)
//   manipulate(1, true, 800);
//   moveCenter(900);
//
// }
//
// void auton6StatRight() {
//   resetEncoders();
//   core(400, false);
//   moveCenter(450);
//   flip(450, -1, true);
//   claw(500, true); // put preload on stationary goal
//   core(150, true);
//   flip(450, 1, true);
//   turn(-95); // turn to face 2nd cone
//   flip(450, -1, true);
//   core(-400, true);
//   claw(-750, true); // pick up 2nd cone
//   flip(450, 1, true);
//   turn(95);
//   core(450, false);
//   flip(450, -1, true);
//   claw(500, true); // put 2nd cone on stationary goal
//   core(150, false);
//   flip(250, 1, false);
//   turn(-45);
//   flip(150, -1, false);
//   moveCenter(300);
//   core(-450, true);
//   claw(-250, false); // put preload on stationary goal
//   moveCenter(-450);
//
//
//
// }
//
// void auton6StatLeft() {
//   resetEncoders();
//   core(400, false);
//   moveCenter(450);
//   flip(450, -1, true);
//   claw(500, true); // put preload on stationary goal
//   core(150, true);
//   flip(450, 1, true);
//   turn(95); // turn to face 2nd cone
//   flip(450, -1, true);
//   core(-400, true);
//   claw(-750, true); // pick up 2nd cone
//   flip(450, 1, true);
//   core(450, false);
//   turn(-90);
//   flip(450, -1, true);
//   claw(500, true); // put 2nd cone on stationary goal
//   core(150, false);
//   flip(250, 1, false);
//   turn(50);
//   flip(150, -1, false);
//   moveCenter(350);
//   core(-450, true);
//   claw(-250, false);
//   moveCenter(-550);
//
// }
//
// void autonSabatogeLeft() {
//   resetEncoders();
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(400)
//   turn(-45)
//   driveF(127)
//   wait1Msec(2500)
//   driveF(0)
// }
//
// void autonSabatogeRight() {
//   resetEncoders();
//   manipulate(1, false);
//   while(800 > fabs(EncoderGetValue(MANIPULATOR))) {}
//   moveCenter(400)
//   turn(45)
//   driveF(127)
//   wait1Msec(2500)
//   driveF(0)
// }

void autonFuncTest() {
  flip(0, true);
  flip(0, true);
  flip(0, true);
  flip(0, true);

}



#endif
