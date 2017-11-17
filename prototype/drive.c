#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

typedef struct {
  bool canMove;

  int goToNum;
  int spd;
} Drive;

Drive drive;

// requires: null
// modifies: links smart motors and sets default values for drive
// affects:  smart motor readout
void driveInit() {

  SmartMotorLinkMotors(LF_DRIVE, LB_DRIVE);
  SmartMotorLinkMotors(RF_DRIVE, RB_DRIVE);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

}

void driveL(int spd) {
  SetMotor(LF_DRIVE, spd, true);
  SetMotor(LB_DRIVE, spd, true);
}

void driveR(int spd) {
  SetMotor(RF_DRIVE, spd, true);
  SetMotor(RB_DRIVE, spd, true);
}

void DriveF(int spd) {
  driveL(spd);
  driveR(spd);
}

// requires: null
// modifies: null
// affects:  lets operator control the drive train
void OPDrive() {
  driveL(TANK_CONTORL_LEFT);
  driveR(TANK_CONTORL_RIGHT);
}

task moveForward_() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  DriveF(drive.spd);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}

  DriveF(0);


  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  writeDebugStream("end fow\n");

  stopTask(moveForward_);


}

task turn_() {


  float prevGyro = SensorValue[GYRO_PORT];

  driveL( fabs(drive.spd) * (sgn(drive.spd)));
  driveR(-fabs(drive.spd) * (sgn(drive.spd)));


  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  DriveF(0);

  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  writeDebugStream("end turn\n");
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
