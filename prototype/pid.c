#ifndef _PROTOTYPE_PID_
#define _PROTOTYPE_PID_

#define MAX_MOTOR_SPEED 127
#define MIN_MOTOR_SPEED (-127)


typedef struct {

  int request;
  int current;

  int error;
  int prevError;

  int P;
  int I;
  int D;

  int kP;
  int kI;
  int kD;

  int iLim;

  tMotor  motor;
  tSensor sensor;

} PIDcontrol;


void pidInit(PIDcontrol &pid,
             int request, int current,
             tMotor m, tSensor s,
             int KP = 0, int KI = 0, int KD = 0) {

  pid.request = request;
  pid.current = current;
  pid.error = current - request;
  pid.prevError = pid.error;


  pid.kP = KP;
  pid.Ki = KI;
  pid.Kd = KD;

  pid.motor = m;
  pid.sensor = s;

}

void SetRequest(PIDcontrol *pid, int request) {
  *pid.request = request;
}

int pid(PIDcontrol *pid) {




  return 0;
}


#endif
