#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_

typedef struct {

  bool canMove;

  int flipAmt;
  int coreAmt;
  int clawAmt;

  int flipSpd;
  int coreSpd;
  int clawSpd;

} Lift;

Lift lift;


// requires: null
// modifies: gives lift appropriate default values
// affects:  the pointed variable
void liftInit() {

  lift.canMove = true;

}

// requires: null
// modifies: null
// affects:  lets operator control the lift
void OPLift() {

  SetMotor(B_CORE_LIFT,
           CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);

  SetMotor(T_CORE_LIFT,
           CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);
  SetMotor(FLIP_LIFT,
           FLIP_LIFT_UP ? 127 : FLIP_LIFT_DOWN ? -127 : 0);

  SetMotor(LIFT_CLAW,
           LIFT_CLAW_UP ? 127 : LIFT_CLAW_DOWN ? -127 : 0);


}

// requires: task
// modifies: lift
// affects:  move the flip bar
task flip_() {
  EncoderSetValue(FLIP_LIFT, 0);

  SetMotor(FLIP_LIFT, 127 * lift.flipSpd);

  while(fabs(lift.flipAmt) > fabs(EncoderGetValue(FLIP_LIFT))) {}

  SetMotor(FLIP_LIFT, 0);

  EncoderSetValue(FLIP_LIFT, 0);

  lift.canMove = true;
  lift.flipSpd = 0;



  stopTask(flip_);
}

// requires: amount to move (encoder tics),
//           speed to move the flip lift at
//           if the program should contiue before the action finishes
// modifies: lift
// affects:  spawn a task to move the flip lift
void flip(int flipAmt, int flipSpd, bool waitForEnd) {


  lift.canMove = false;
  lift.flipSpd = flipSpd;
  lift.flipAmt = flipAmt;

  startTask(flip_);

  while(waitForEnd && !lift.canMove){}
}

// requires: task
// modifies: lift
// affects:  move the combine
// the name of "claw" is due to our original use of a claw instead of a combine
task claw_() {
  SetMotor(LIFT_CLAW, 127 * (sgn(lift.clawAmt)));

  wait1Msec(abs(lift.clawAmt));

  SetMotor(LIFT_CLAW, 0);


  lift.canMove = true;
  lift.clawAmt = 0;


  EncoderSetValue(LIFT_CLAW, 0);

  stopTask(claw_);
}
// requires: amount to move (wait time),
//           if the program should contiue before the action finishes
// modifies: lift
// affects:  spawn a task to move the combine
// the name of "claw" is due to our original use of a claw instead of a combine
void claw(int amt, bool waitForEnd) {

  lift.canMove = false;
  lift.clawAmt = amt;

  startTask(claw_);

  while(waitForEnd && !lift.canMove){}
}

// requires: task
// modifies: lift
// affects:  move the core lift
task core_() {
  EncoderSetValue(B_CORE_LIFT, 0);

  SetMotor(B_CORE_LIFT, 127 * (sgn(lift.coreAmt)));
  SetMotor(T_CORE_LIFT, 127 * (sgn(lift.coreAmt)));

  while(fabs(lift.coreAmt) > fabs(EncoderGetValue(B_CORE_LIFT))) {}

  SetMotor(B_CORE_LIFT, 0);
  SetMotor(T_CORE_LIFT, 0);


  lift.canMove = true;
  lift.coreAmt = 0;


  EncoderSetValue(B_CORE_LIFT, 0);

  stopTask(core_);
}
// requires: amount to move (encoder tics),
//           if the program should contiue before the action finishes
// modifies: lift
// affects:  spawn a task to move the core lift
void core(int amt, bool waitForEnd) {

  lift.canMove = false;
  lift.coreAmt = amt;

  startTask(core_);

  while(waitForEnd && !lift.canMove){};
}


#endif
