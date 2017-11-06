#ifndef _PROTOTYPE_OPERATOR_CONTORL_
#define _PROTOTYPE_OPERATOR_CONTORL_


task taskOPCdrive() {
  while(true) {
    OPDrive(robot.drive);
  }
}

task taskOPCmanipulate() {
  while(true) {
    OPManipulate(robot.manipulator);
  }
}

task taskOPClift() {
  while(true) {
    OPLift(robot.lift);
  }
}


#endif
