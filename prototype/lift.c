#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_

typedef struct {

  tMotor *coreMotorL;
  tMotor *coreMotorR;

  tMotor *flipMotor;

  tMotor *clawMotor;


} Lift;

void liftInit(Lift *lift) {
  *lift->coreMotorL = L_CORE_LIFT;
  *lift->coreMotorR = R_CORE_LIFT;
  *lift->flipMotor =  FLIP_LIFT;
  *lift->clawMotor =  LIFT_CLAW;

  SmartMotorLinkMotors(*lift->coreMotorL, *lift->coreMotorR);

}


#endif
