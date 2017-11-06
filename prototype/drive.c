#ifndef _PROTOTYPE_DRIVE_
#define _PROTOTYPE_DRIVE_

typedef struct {
  tMotor *RFmotor;
  tMotor *RBmotor;

  tMotor *LFmotor;
  tMotor *LBmotor;

} Drive;

// requires: pointer to drive variable
// modifies: gives drive appropriate default values
// affects:  the pointed variable
void driveInit(Drive *drive) {

  *drive->RFmotor = RF_DRIVE;
  *drive->RBmotor = RB_DRIVE;

  *drive->LFmotor = LF_DRIVE;
  *drive->LBmotor = LB_DRIVE;

  SmartMotorLinkMotors(*drive->RFmotor, *drive->RBmotor);
  SmartMotorLinkMotors(*drive->LFmotor, *drive->LBmotor);
}


// requires: pointer to drive variable
// modifies: null
// affects:  lets operator control the drive train
void OPDrive(Drive *drive) {
  SetMotor(*drive->RFmotor, TANK_CONTORL_LEFT);
  SetMotor(*drive->RBmotor, TANK_CONTORL_LEFT);

  SetMotor(*drive->LFmotor, TANK_CONTORL_LEFT);
  SetMotor(*drive->LBmotor, TANK_CONTORL_LEFT);
}


#endif
