#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

typedef struct {
  bool canMove;
  int goToNum;
} Drive;

Drive drive;

// requires: null
// modifies: links smart motors
// affects:  smart motor readout
void driveInit() {

  SmartMotorLinkMotors(LF_DRIVE, LB_DRIVE);
  SmartMotorLinkMotors(RF_DRIVE, RB_DRIVE);

  drive.canMove = true;
  drive.goToNum = 0;
}

void leftControlDrive(int spd) {
  SetMotor(LF_DRIVE, spd);
  SetMotor(LB_DRIVE, spd);
}

void rightControlDrive(int spd) {
  SetMotor(RF_DRIVE, spd);
  SetMotor(RB_DRIVE, spd);
}

void totalControlDrive(int spd) {
  leftControlDrive(spd);
  rightControlDrive(spd);
}

// requires: null
// modifies: null
// affects:  lets operator control the drive train
void OPDrive() {

  leftControlDrive(TANK_CONTORL_LEFT);
  rightControlDrive(TANK_CONTORL_RIGHT);

}

task moveForward_() {
  EncoderSetValue(LF_DRIVE, 0);

  while(drive.goToNum > EncoderGetValue(LF_DRIVE) && drive.goToNum > EncoderGetValue(RF_DRIVE)) {
    totalControlDrive(127 * sgn(drive.goToNum));
  }

  stopTask(moveForward_);
  drive.canMove = true;
  drive.goToNum = 0;
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

}

void moveForward(int amt) {
  if(!drive.canMove) return;

  drive.canMove = false;
  drive.goToNum = amt;

  startTask(moveForward_);

}

#endif
