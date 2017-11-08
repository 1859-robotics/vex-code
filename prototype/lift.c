#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_

#define FLIP_LIFT_AMT 700

typedef struct {

  bool canMove;
  int dir;

} Flipper;

Flipper flipper;


// requires: pointer to lift variable
// modifies: gives lift appropriate default values
// affects:  the pointed variable
void liftInit() {

  flipper.dir = 0;
  flipper.canMove = true;

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

  SetMotor(FLIP_LIFT, 127 * flipper.dir);

  while(FLIP_LIFT_AMT > fabs(EncoderGetValue(FLIP_LIFT))) {}

  SetMotor(FLIP_LIFT, 0);


  flipper.canMove = true;
  flipper.dir = 0;


  EncoderSetValue(FLIP_LIFT, 0);

  stopTask(flip_);
}

void flip(int dir) {
  
  while(!flipper.canMove){};

  flipper.canMove = false;
  flipper.dir = dir;

  startTask(flip_);

  while(!flipper.canMove){};
}



#endif
