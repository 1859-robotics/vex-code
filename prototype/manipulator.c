#ifndef _PROTOTYPE_MANIPULATOR_
#define _PROTOTYPE_MANIPULATOR_

#define MANIPULATOR_DIST 1600
#define MANIPULATOR_END_DIST 1600


typedef struct {

  bool canMove;
  int dir;
  int amt;

} Manipulator;

Manipulator manipulator;

// requires: null
// modifies: gives manipulator appropriate default values
// affects:  manipulator
void maniplulatorInit() {
  manipulator.dir = 0;
  manipulator.canMove = true;

}

// requires: pointer to manipulator variable
// modifies: null
// affects:  lets operator control the manipulator
void OPManipulate() {

    SetMotor(MANIPULATOR,
             MANIPULATOR_UP ? 100 : MANIPULATOR_DOWN ? -100 : MANIPULATOR_DOWN_FAST ? 127 : MANIPULATOR_UP_FAST ? -127 : 0);

}

task manipulate_() {
  EncoderSetValue(MANIPULATOR, 0);

  SetMotor(MANIPULATOR, 127 * manipulator.dir);

  while(manipulator.amt > fabs(EncoderGetValue(MANIPULATOR))) {}
  manipulator.canMove = true;

  SetMotor(MANIPULATOR, 0);


  manipulator.dir = 0;


  EncoderSetValue(MANIPULATOR, 0);

  stopTask(manipulate_);
}

void manipulate(int dir, bool waitForEnd) {
  while(!manipulator.canMove){};

  manipulator.canMove = false;
  manipulator.dir = dir;
  manipulator.amt = MANIPULATOR_DIST;

  startTask(manipulate_);

  while(waitForEnd && !manipulator.canMove) {
    writeDebugStream("waiting\n");
  }
}

void manipulate(int dir, bool waitForEnd, int amt) {
  while(!manipulator.canMove){};

  manipulator.canMove = false;
  manipulator.dir = dir;
  manipulator.amt = amt;

  startTask(manipulate_);

  while(waitForEnd && !manipulator.canMove) {
    writeDebugStream("waiting\n");
  }
}


#endif
