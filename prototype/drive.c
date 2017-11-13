#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

typedef struct {
  bool canMove;

  int goToNum;
  int spd;
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
  drive.spd = 0;

}

void driveL(int spd) {
  SetMotor(LF_DRIVE, spd);
  SetMotor(LB_DRIVE, spd);
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


  SetMotor(LF_DRIVE, drive.spd, true);
  SetMotor(LB_DRIVE, drive.spd, true);
  SetMotor(RF_DRIVE, drive.spd, true);
  SetMotor(RB_DRIVE, drive.spd, true);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}


  SetMotor(LF_DRIVE, 0, true);
  SetMotor(LB_DRIVE, 0, true);
  SetMotor(RF_DRIVE, 0, true);
  SetMotor(RB_DRIVE, 0, true);


  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;



  stopTask(moveForward_);


}

task turn_() {


  SetMotor(LF_DRIVE,  drive.spd * (sgn(drive.spd)), true);
  SetMotor(LB_DRIVE,  drive.spd * (sgn(drive.spd)), true);
  SetMotor(RF_DRIVE, -drive.spd * (sgn(drive.spd)), true);
  SetMotor(RB_DRIVE, -drive.spd * (sgn(drive.spd)), true);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}


  SetMotor(LF_DRIVE, 0, true);
  SetMotor(LB_DRIVE, 0, true);
  SetMotor(RF_DRIVE, 0, true);
  SetMotor(RB_DRIVE, 0, true);

  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;



  stopTask(turn_);


}


void moveForward(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveForward_);

  while(waitForEnd && !drive.canMove){};
}

void turn(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(turn_);

  while(waitForEnd && !drive.canMove){};
}

#endif
