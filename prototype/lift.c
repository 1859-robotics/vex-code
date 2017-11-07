#ifndef _PROTOTYPE_LIFT_
#define _PROTOTYPE_LIFT_


// requires: pointer to lift variable
// modifies: gives lift appropriate default values
// affects:  the pointed variable
void liftInit() {

  SmartMotorLinkMotors(L_CORE_LIFT, R_CORE_LIFT);

}

// requires: pointer to lift variable
// modifies: null
// affects:  lets operator control the lift
void OPLift() {

  SetMotor(L_CORE_LIFT,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);

  SetMotor(R_CORE_LIFT,
            CORE_LIFT_UP ? 127 : CORE_LIFT_DOWN ? -127 : 0);


  SetMotor(FLIP_LIFT,
            FLIP_LIFT_UP ? 127 : FLIP_LIFT_DOWN ? -127 : 0);


  SetMotor(LIFT_CLAW,
            LIFT_CLAW_UP ? 127 : LIFT_CLAW_DOWN ? -127 : 0);

}

#endif
