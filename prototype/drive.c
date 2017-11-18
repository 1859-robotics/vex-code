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


// requires: null
// modifies: null
// affects:  short hand function for controlling the left side of the drive
void driveL(int spd) {
  SetMotor(LF_DRIVE, spd, true);
  SetMotor(LB_DRIVE, spd, true);
}


// requires: null
// modifies: null
// affects:  short hand function for controlling the right side of the drive
void driveR(int spd) {
  SetMotor(RF_DRIVE, spd, true);
  SetMotor(RB_DRIVE, spd, true);
}


// requires: null
// modifies: null
// affects:  short hand function for controlling the entire drive
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

task moveCenter_() {
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  DriveF(drive.spd);

  // while the encoder values are not the requseted value
  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}

  DriveF(0); // equivilant to stoping all drive motors

  // reset encoders
  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  // reset drive values
  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;


  stopTask(moveCenter_);


}

task moveLeftEncoder_() {
  EncoderSetValue(LF_DRIVE, 0);

  driveL(drive.spd);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LF_DRIVE))) {}

  driveL(0);


  EncoderSetValue(LF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  writeDebugStream("end left\n");
  stopTask(moveLeftEncoder_);
}

task moveRightEncoder_() {
  EncoderSetValue(RF_DRIVE, 0);

  driveR(drive.spd);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(RF_DRIVE))) {}

  driveR(0);


  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  writeDebugStream("end right\n");
  stopTask(moveRightEncoder_);


}

task moveLeftGyro_() {
  EncoderSetValue(LF_DRIVE, 0);

  float prevGyro = SensorValue[GYRO_PORT];

  driveL(drive.spd);

  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  driveL(0);


  EncoderSetValue(LF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  stopTask(moveLeftGyro_);
}

task moveRightGyro_() {
  EncoderSetValue(RF_DRIVE, 0);

  float prevGyro = SensorValue[GYRO_PORT];

  driveR(drive.spd);

  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  driveR(0);


  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  stopTask(moveRightGyro_);


}


task turn_() {

  // store previos gyro for locally zeroing value
  float prevGyro = SensorValue[GYRO_PORT];


  driveL( fabs(drive.spd) * (sgn(drive.spd)));
  driveR(-fabs(drive.spd) * (sgn(drive.spd)));


  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  DriveF(0);

  EncoderSetValue(LF_DRIVE, 0);
  EncoderSetValue(RF_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;

  stopTask(turn_);
}


void moveCenter(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveCenter_);

  while(waitForEnd && !drive.canMove){};
}

void moveLeftEncoder(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveLeftEncoder_);

  while(waitForEnd && !drive.canMove){};
}

void moveRightEncoder(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveRightEncoder_);

  while(waitForEnd && !drive.canMove){};
}

void moveRightGyro(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveRightGyro_);

  while(waitForEnd && !drive.canMove){};
}

void moveLeftGyro(int amt, int spd, bool waitForEnd) {
  while(!drive.canMove){};

  drive.canMove = false;
  drive.goToNum = amt;
  drive.spd = spd;

  startTask(moveLeftGyro_);

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
