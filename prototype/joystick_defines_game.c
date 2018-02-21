#ifndef _JOYSTICK_
#define _JOYSTICK_

#define TANK_CONTORL_LEFT        vexRT[Ch3]
#define TANK_CONTORL_RIGHT       vexRT[Ch2]

#define FLIP_LIFT_UP             vexRT[Btn5D] && !vexRT[Btn5U]
#define FLIP_LIFT_DOWN           vexRT[Btn5U] && !vexRT[Btn5D]

#define CORE_LIFT_UP             vexRT[Btn6U] && !vexRT[Btn6D]
#define CORE_LIFT_DOWN           vexRT[Btn6D] && !vexRT[Btn6U]

#define LIFT_CLAW_UP             vexRT[Btn8D]
#define LIFT_CLAW_DOWN           vexRT[Btn8R]

#define MANIPULATOR_UP           vexRT[Btn7D]
#define MANIPULATOR_DOWN         vexRT[Btn7L]
#define MANIPULATOR_DOWN_FAST    vexRT[Btn7U] || (vexRT[Btn5D] && vexRT[Btn5U])
#define MANIPULATOR_UP_FAST      vexRT[Btn7R] || (vexRT[Btn6U] && vexRT[Btn6D])





#endif