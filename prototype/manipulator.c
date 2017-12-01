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

}

// requires: pointer to manipulator variable
// modifies: null
// affects:  lets operator control the manipulator
void OPManipulate() {

    SetMotor(MANIPULATOR,
              MANIPULATOR_UP ? 127 : MANIPULATOR_DOWN ? -127 : 0);


}

task manipulate_() {

  SetMotor(MANIPULATOR, 127 * manipulator.dir);

  while(MANIPULATOR_DIST > fabs(EncoderGetValue(MANIPULATOR))) {}

  SetMotor(MANIPULATOR, 0);


  manipulator.canMove = true;
  manipulator.dir = 0;


  EncoderSetValue(MANIPULATOR, 0);

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
