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

void OPManipulate(Manipulator *manipulator) {

    SetMotor(*manipulator->lMotor,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

    SetMotor(*manipulator->rMotor,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

}


#endif
