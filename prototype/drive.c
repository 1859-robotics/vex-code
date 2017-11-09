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

// requires: null
// modifies: null
// affects:  lets operator control the drive train
void OPDrive() {

  SetMotor(LF_DRIVE, TANK_CONTORL_LEFT);
  SetMotor(LB_DRIVE, TANK_CONTORL_LEFT);

  SetMotor(RF_DRIVE, TANK_CONTORL_RIGHT);
  SetMotor(RB_DRIVE, TANK_CONTORL_RIGHT);


}

task moveForward_() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);


  SetMotor(LF_DRIVE, 127 * (sgn(drive.goToNum)));
  SetMotor(LB_DRIVE, 127 * (sgn(drive.goToNum)));
  SetMotor(RF_DRIVE, 127 * (sgn(drive.goToNum)));
  SetMotor(RB_DRIVE, 127 * (sgn(drive.goToNum)));

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}


  SetMotor(LF_DRIVE, 0);
  SetMotor(LB_DRIVE, 0);
  SetMotor(RF_DRIVE, 0);
  SetMotor(RB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);


  stopTask(moveForward_);


}

task turn_() {


  SetMotor(LF_DRIVE, 127 * -(sgn(drive.goToNum)));
  SetMotor(LB_DRIVE, 127 * -(sgn(drive.goToNum)));
  SetMotor(RF_DRIVE, 127 * (sgn(drive.goToNum)));
  SetMotor(RB_DRIVE, 127 * (sgn(drive.goToNum)));

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}


  SetMotor(LF_DRIVE, 0);
  SetMotor(LB_DRIVE, 0);
  SetMotor(RF_DRIVE, 0);
  SetMotor(RB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);


  stopTask(moveForward_);


}


void moveForward(int amt, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;

  startTask(moveForward_);

  while(waitForEnd && !drive.canMove){};
}

void turn(int amt, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;

  startTask(turn_);

  while(waitForEnd && !drive.canMove){};
}

#endif
