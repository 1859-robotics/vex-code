#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

typedef struct {
  bool canMove;

  int goToNum;
  int spd;

  PID gyroPID;
  Gyro gyro;

} Drive;

Drive drive;

// requires: null
// modifies: links smart motors and sets default values for drive
// affects:  smart motor readout
void driveInit() {

  SmartMotorLinkMotors(LB_DRIVE, LF_DRIVE);
  SmartMotorLinkMotors(RB_DRIVE, RF_DRIVE);

  SmartMotorsAddPowerExtender(LF_DRIVE, RF_DRIVE, LB_DRIVE)

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  gyroInit(drive.gyro, GYRO_PORT);

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

// requires: task
// modifies: 0's drive encoders
// affects:  moves forward by amount specified in drive
task moveCenter_() {
  EncoderSetValue(LB_DRIVE, 0);
  EncoderSetValue(RB_DRIVE, 0);

  DriveF(drive.spd);

  // while the encoder values are not the requseted value
  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LB_DRIVE)) ||
        fabs(drive.goToNum) > fabs(EncoderGetValue(RB_DRIVE))) {}

  DriveF(0); // equivilant to stoping all drive motors

  // reset encoders
  EncoderSetValue(LB_DRIVE, 0);
  EncoderSetValue(RB_DRIVE, 0);

  // reset drive values
  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;


  stopTask(moveCenter_);

}



task moveLeftEncoder_() {
  EncoderSetValue(LB_DRIVE, 0);

  driveL(drive.spd);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(LB_DRIVE))) {}

  driveL(0);


  EncoderSetValue(LB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  writeDebugStream("end left\n");
  stopTask(moveLeftEncoder_);
}

task moveRightEncoder_() {
  EncoderSetValue(RB_DRIVE, 0);

  driveR(drive.spd);

  while(fabs(drive.goToNum) > fabs(EncoderGetValue(RB_DRIVE))) {}

  driveR(0);


  EncoderSetValue(RB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  writeDebugStream("end right\n");
  stopTask(moveRightEncoder_);


}

task moveLeftGyro_() {
  EncoderSetValue(LB_DRIVE, 0);

  float prevGyro = SensorValue[GYRO_PORT];

  driveL(drive.spd);

  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  driveL(0);


  EncoderSetValue(LB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  stopTask(moveLeftGyro_);
}

task moveRightGyro_() {
  EncoderSetValue(RB_DRIVE, 0);

  float prevGyro = SensorValue[GYRO_PORT];

  driveR(drive.spd);

  while(fabs(prevGyro - SensorValue[GYRO_PORT]) / 10 < drive.goToNum) {}

  driveR(0);


  EncoderSetValue(RB_DRIVE, 0);

  drive.canMove = true;
  drive.goToNum = 0;
  drive.spd = 0;

  stopTask(moveRightGyro_);


}


task turn_() {
  if(abs(drive.goToNum) < 40)
		pidInit(drive.gyroPID, 3.0, 0.0, 0.15, 3.0, 30.0);

  bool atGyro = false;
	long targetTime = nPgmTime;
	long timer = nPgmTime;
	float gyroAngle = 0;

	while(!atGyro){
		//Calculate the delta time from the last iteration of the loop
		float fDeltaTime = (float)(nPgmTime - timer)/1000.0;
		//Reset loop timer
		timer = nPgmTime;

		gyroAngle += gyroGetRate(drive.gyro) * fDeltaTime;

		//Calculate the output of the PID controller and output to drive motors
		float driveOut = pidCalculate(drive.gyroPID, drive.goToNum, gyroAngle);
		driveL(-driveOut);
		driveR(driveOut);

		//Stop the turn function when the angle has been within 3 degrees of the desired angle for 350ms
		if(abs(drive.goToNum - gyroAngle) > 3)
			targetTime = nPgmTime;
		if(nPgmTime - targetTime > 350){
			atGyro = true;
			driveL(0);
			driveR(0);
		}
	}

	//Reinitialize the PID constants to their original values in case they were changed
	pidInit(drive.gyroPID, 2, 0, 0.15, 2, 20.0);

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
