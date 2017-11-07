#ifndef _PROTOTYPE_OPERATOR_CONTORL_
#define _PROTOTYPE_OPERATOR_CONTORL_

#define WAIT_TIME 20

// each one of these allows the user to control a particular part of the bot

task taskOPCdrive() {
  while(true) {
    OPDrive();

    wait1Msec(WAIT_TIME);
  }
}

task taskOPCmanipulate() {
  while(true) {
    OPManipulate();

    wait1Msec(WAIT_TIME);
  }
}

task taskOPClift() {
  while(true) {
    OPLift();

    wait1Msec(WAIT_TIME);
  }
}


#endif
