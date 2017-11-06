#ifndef _PROTOTYPE_MANIPULATOR_
#define _PROTOTYPE_MANIPULATOR_

typedef struct {

  tMotor *lMotor;
  tMotor *rMotor;

} Manipulator;

// requires: pointer to manipulator variable
// modifies: gives manipulator appropriate default values
// affects:  the pointed variable
void maniplulatorInit(Manipulator *manipulator) {
  *manipulator->lMotor = L_MANIPULATOR;
  *manipulator->rMotor = R_MANIPULATOR;

  SmartMotorLinkMotors(*manipulator->lMotor, *manipulator->rMotor);
}

// requires: pointer to manipulator variable
// modifies: null
// affects:  lets operator control the manipulator
void OPManipulate(Manipulator *manipulator) {

    SetMotor(*manipulator->lMotor,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

    SetMotor(*manipulator->rMotor,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

}


#endif
