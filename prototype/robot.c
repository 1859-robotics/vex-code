#ifndef _PROTOTYPE_ROBOT_
#define _PROTOTYPE_ROBOT_

typedef struct {

  Drive       drive;
  Lift        lift;
  Manipulator manipulator;

} Robot;

Robot robot;

void robotInit(Robot *robot) {

  driveInit(robot->drive);
  liftInit(robot->lift);
  maniplulatorInit(robot->manipulator);

}


#endif
