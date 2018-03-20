#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

#define PID_TOLERANCE 3 /* the tolerance for turns */
#define ENCODER_PID_TOLERANCE 150 /* the tolerance for movement */
#define MAX_SPEED 127 /* the maximum speed of the bot */
#define MIN_SPEED 30 /* the minimum speed of the bot */
#define MIN_SPEED_TURN 40 /* the minimum speed of turns */
#define MIN_OP_SPD 20 /* the minimum input for the drive to fire */
#define SLOW_DOWN_SPD 30 /* the slow down speed for movement */
#define SLOW_DOWN_ENCODER_S 200 /* the encoder values for slowdown */
#define SLOW_DOWN_ENCODER_N 300 /* the encoder values for slowdown */

typedef struct {
  bool canMove;

  int target;
  int spd;
  int gyroAngle;
  Gyro gyro;
  PID pid;
} Drive;

Drive drive;

// requires: null
// modifies: links smart motors and sets default values for drive
// affects:  smart motor readout
void driveInit() {
  drive.canMove = true;
  drive.target = 0;
  drive.spd = 0;

  gyroInit(drive.gyro, GYRO_PORT)
}


// requires: null
// modifies: null
// affects:  short hand function for controlling the left side of the drive
void driveL(int spd, bool i = false) {
  SetMotor(LF_DRIVE, spd, i);
  SetMotor(LB_DRIVE, spd, i);
}


// requires: null
// modifies: null
// affects:  short hand function for controlling the right side of the drive
void driveR(int spd, bool i = false) {
  SetMotor(RF_DRIVE, spd, i);
  SetMotor(RB_DRIVE, spd, i);
}


// requires: null
// modifies: null
// affects:  short hand function for controlling the entire drive
void driveF(int spd) {
  driveL(spd, true);
  driveR(spd, true);
}

// requires: null
// modifies: null
// affects:  lets operator control the drive train
void OPDrive() {
  driveL(abs(TANK_CONTORL_LEFT)  > MIN_OP_SPD ? TANK_CONTORL_LEFT  : 0);
  driveR(abs(TANK_CONTORL_RIGHT) > MIN_OP_SPD ? TANK_CONTORL_RIGHT : 0);
}

// requires: task
// modifies: zero's all drive encoders
// affects:  moves forward by amount specified in drive
task moveCenter_() {

  if(abs(drive.target) < 200)
    pidInit(drive.pid, 3.0, 0.0, 0.15, 3.0, 30.0, MIN_SPEED, MAX_SPEED);
  else
    pidInit(drive.pid, 2, 0, 0.15, 2, 20.0, MIN_SPEED, MAX_SPEED);
  bool bAtTarget = false;
  long liAtTargetTime = nPgmTime;
  float fEncoderVal = 0;
  float fStartMin = SLOW_DOWN_ENCODER_N;
  if(drive.target < 400) {
    fStartMin = SLOW_DOWN_ENCODER_S;
  }
  EncoderSetValue(LB_DRIVE, 0);
  EncoderSetValue(RB_DRIVE, 0);
  while(!bAtTarget) {

    fEncoderVal = (EncoderGetValue(LB_DRIVE) + EncoderGetValue(RB_DRIVE)) / 2;

    //Calculate the output of the PID controller and output to drive motors
    float driveOut = pidCalculate(drive.pid, drive.target, fEncoderVal);
    if(abs(drive.target - fEncoderVal) < fStartMin) {
      driveOut = SLOW_DOWN_SPD * sgn(driveOut);
    }

    driveF(-driveOut);

    if(abs(drive.target - fEncoderVal) > ENCODER_PID_TOLERANCE) {
      liAtTargetTime = nPgmTime;
    }
    if(nPgmTime - liAtTargetTime > 350) {
      bAtTarget = true;
      driveF(0);
    }
  }

  //Reinitialize the PID constants to their original values in case they were changed
  pidInit(drive.pid, 2, 0, 0.15, 2, 20.0, MIN_SPEED, MAX_SPEED);

  drive.canMove = true;
  drive.target =  0;
  stopTask(moveCenter_)
}


// requires: target (encdoder tics)
// modifies: drive.pid
// affects:  turn the robot by the specified degrees
void moveCenter(float fTarget, bool bWait) {

  while(!drive.canMove){};

  drive.canMove = false;
  drive.target = -fTarget;

  startTask(moveCenter_);

  while(bWait && !drive.canMove){}



}

// requires: target (deg) and pid
// modifies: drive.pid
// affects:  turn the robot by the specified degrees
void turn(float fTarget) {
	if(abs(fTarget) < 40)
		pidInit(drive.pid, 3.0, 0.0, 0.15, 3.0, 30.0, MIN_SPEED_TURN, MAX_SPEED);
  else
    pidInit(drive.pid, 2.0, 0.0, 0.15, 2.0, 20.0, MIN_SPEED_TURN, MAX_SPEED);

	bool bAtGyro = false;
	long liAtTargetTime = nPgmTime;
	long liTimer = nPgmTime;
	float fGyroAngle = 0;
  float fPrevGyro = SensorValue(drive.gyro.m_iPortNum);
	while(!bAtGyro) {
		//Calculate the delta time from the last iteration of the loop
		// float fDeltaTime = (float)(nPgmTime - liTimer)/1000.0;
		//Reset loop timer
		liTimer = nPgmTime;

		// fGyroAngle += gyroGetRate(drive.gyro) * fDeltaTime;
    fGyroAngle = (SensorValue(drive.gyro.m_iPortNum) - fPrevGyro) / 10;

		//Calculate the output of the PID controller and output to drive motors
		float driveOut = pidCalculate(drive.pid, fTarget, fGyroAngle);
		driveL(-driveOut);
		driveR(driveOut);

		if(abs(fTarget - fGyroAngle) > PID_TOLERANCE) {
      liAtTargetTime = nPgmTime;
    }
		if(nPgmTime - liAtTargetTime > 350) {
			bAtGyro = true;
			driveF(0);
		}
	}

	//Reinitialize the PID constants to their original values in case they were changed
	pidInit(drive.pid, 2, 0, 0.15, 2, 20.0, MIN_SPEED, MAX_SPEED);
}


#endif
