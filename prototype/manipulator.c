#ifndef _PROTOTYPE_MANIPULATOR_
#define _PROTOTYPE_MANIPULATOR_

typedef struct {

  tMotor *lMotor;
  tMotor *rMotor;

} Manipulator;


void maniplulatorInit(Manipulator *manipulator) {
  *manipulator->lMotor = L_MANIPULATOR;
  *manipulator->rMotor = R_MANIPULATOR;

  SmartMotorLinkMotors(*manipulator->lMotor, *manipulator->rMotor);
}


#endif
