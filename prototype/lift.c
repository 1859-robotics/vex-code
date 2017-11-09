#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_

#define FLIP_LIFT_AMT 450

typedef struct {

  bool canMove;
  int flipDir;
  int coreAmt;
  int clawAmt;

} Lift;

Lift lift;


// requires: pointer to lift variable
// modifies: gives lift appropriate default values
// affects:  the pointed variable
void liftInit() {

  lift.flipDir = 0;
  lift.canMove = true;

  SmartMotorLinkMotors(L_CORE_LIFT, R_CORE_LIFT);

}

// requires: pointer to lift variable
// modifies: null
// affects:  lets operator control the lift
void OPLift() {

  SetMotor(L_CORE_LIFT,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);

  SetMotor(R_CORE_LIFT,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);


  SetMotor(FLIP_LIFT,
            FLIP_LIFT_UP ? 127 : FLIP_LIFT_DOWN ? -127 : 0);


  SetMotor(LIFT_CLAW,
            LIFT_CLAW_UP ? 127 : LIFT_CLAW_DOWN ? -127 : 0);

}

task flip_() {

  SetMotor(FLIP_LIFT, 127 * lift.flipDir);

  while(FLIP_LIFT_AMT > fabs(EncoderGetValue(FLIP_LIFT))) {}

  SetMotor(FLIP_LIFT, 0);


  lift.canMove = true;
  lift.flipDir = 0;


  EncoderSetValue(FLIP_LIFT, 0);

  stopTask(flip_);
}

void flip(int flipDir, bool waitForEnd) {

  while(!lift.canMove){}

  lift.canMove = false;
  lift.flipDir = flipDir;

  startTask(flip_);

  while(waitForEnd && !lift.canMove){}
}


task claw_() {
  SetMotor(LIFT_CLAW, 127 * (sgn(lift.clawAmt)));

  while(fabs(lift.clawAmt) > fabs(EncoderGetValue(LIFT_CLAW))) {}

  SetMotor(LIFT_CLAW, 0);


  lift.canMove = true;
  lift.clawAmt = 0;


  EncoderSetValue(LIFT_CLAW, 0);

  stopTask(flip_);
}

void claw(int amt, bool waitForEnd) {
  while(!lift.canMove){}

  lift.canMove = false;
  lift.clawAmt = amt;

  startTask(claw_);

  while(waitForEnd && !lift.canMove){}
}

task core_() {
  SetMotor(L_CORE_LIFT, 127 * (sgn(lift.coreAmt)));
  SetMotor(R_CORE_LIFT, 127 * (sgn(lift.coreAmt)));

  while(fabs(lift.coreAmt) > fabs(EncoderGetValue(L_CORE_LIFT))) {}

  SetMotor(L_CORE_LIFT, 0);
  SetMotor(R_CORE_LIFT, 0);


  lift.canMove = true;
  lift.coreAmt = 0;


  EncoderSetValue(L_CORE_LIFT, 0);

  stopTask(core_);
}

void core(int amt, bool waitForEnd) {
  while(!lift.canMove){};

  lift.canMove = false;
  lift.coreAmt = amt;

  startTask(core_);

  while(waitForEnd && !lift.canMove){writeDebugStream("while")};


}


#endif
