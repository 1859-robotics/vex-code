#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_

typedef struct {

  tMotor *coreMotorL;
  tMotor *coreMotorR;

  tMotor *flipMotor;

  tMotor *clawMotor;


} Lift;


// requires: pointer to lift variable
// modifies: gives lift appropriate default values
// affects:  the pointed variable
void liftInit(Lift *lift) {
  *lift->coreMotorL = L_CORE_LIFT;
  *lift->coreMotorR = R_CORE_LIFT;

  *lift->flipMotor =  FLIP_LIFT;

  *lift->clawMotor =  LIFT_CLAW;

  SmartMotorLinkMotors(*lift->coreMotorL, *lift->coreMotorR);

}

// requires: pointer to lift variable
// modifies: null
// affects:  lets operator control the lift
void OPLift(Lift *lift) {

  SetMotor(*lift->coreMotorL,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);

  SetMotor(*lift->coreMotorR,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);


  SetMotor(*lift->flipMotor,
            FLIP_LIFT_UP ? 127 : FLIP_LIFT_DOWN ? -127 : 0);


  SetMotor(*lift->clawMotor,
            LIFT_CLAW_UP ? 127 : LIFT_CLAW_DOWN ? -127 : 0);

}

#endif
