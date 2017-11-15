#ifndef _PROTOTYPE_PID_
#define _PROTOTYPE_PID_

#define MAX_SPEED 127





typedef struct {
  int target;
  int current;

  int error;
  int prevError;

  int p;
  int i;
  int d;




} pidController;


void pidInit() {

}



#endif
