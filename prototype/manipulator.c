#ifndef _PROTOTYPE_MANIPULATOR_
#define _PROTOTYPE_MANIPULATOR_


// requires: pointer to manipulator variable
// modifies: gives manipulator appropriate default values
// affects:  the pointed variable
void maniplulatorInit() {

  SmartMotorLinkMotors(L_MANIPULATOR, R_MANIPULATOR);
}

// requires: pointer to manipulator variable
// modifies: null
// affects:  lets operator control the manipulator
void OPManipulate() {

    SetMotor(L_MANIPULATOR,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

    SetMotor(R_MANIPULATOR,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);

}


#endif
