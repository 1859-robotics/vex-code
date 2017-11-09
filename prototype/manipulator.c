#ifndef _PROTOTYPE_MANIPULATOR_
#define _PROTOTYPE_MANIPULATOR_

#define MANIPULATOR_DIST 400



typedef struct {

  bool canMove;
  int dir;

} Manipulator;

Manipulator manipulator;

// requires: pointer to manipulator variable
// modifies: gives manipulator appropriate default values
// affects:  the pointed variable
void maniplulatorInit() {
  manipulator.dir = 0;
  manipulator.canMove = true;
  SmartMotorLinkMotors(R_MANIPULATOR, L_MANIPULATOR);
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

task manipulate_() {

  SetMotor(R_MANIPULATOR, 127 * manipulator.dir);
  SetMotor(L_MANIPULATOR, 127 * manipulator.dir);

  while(MANIPULATOR_DIST > fabs(EncoderGetValue(R_MANIPULATOR))) {}

  SetMotor(L_MANIPULATOR, 0);
  SetMotor(R_MANIPULATOR, 0);


  manipulator.canMove = true;
  manipulator.dir = 0;


  EncoderSetValue(R_MANIPULATOR, 0);

  stopTask(manipulate_);
}

void manipulate(int dir, bool waitForEnd) {
  while(!manipulator.canMove){};

  manipulator.canMove = false;
  manipulator.dir = dir;

  startTask(manipulate_);

  while(waitForEnd && !manipulator.canMove){};
}


#endif
