#ifndef _DRIVE_
#define _DRIVE_

typedef struct {
  tMotor driveFL;
  tMotor driveFR;
  tMotor driveBL;
  tMotor driveBR;

  bool operatorTrain;
} Drive;

Drive drive;


void driveInit(Drive &drive) {


  drive.driveFL = FL_DRIVE;
  drive.driveFR = BL_DRIVE;
  drive.driveBL = FR_DRIVE;
  drive.driveBR = BR_DRIVE;

  SmartMotorLinkMotors(drive.driveFL, drive.driveFR);
  SmartMotorLinkMotors(drive.driveBL, drive.driveBR);

  drive.operatorTrain = true;

}

task driveTrain() {
  while(drive.operatorTrain) {
    SetMotor(drive.driveFL, TANK_CONTORL_LEFT);
    SetMotor(drive.driveFR, TANK_CONTORL_RIGHT);


    wait1Msec(20);
  }
  stopTask(driveTrain);
}




#endif
