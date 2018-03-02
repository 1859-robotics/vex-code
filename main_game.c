#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    GYRO_PORT,      sensorGyro)
#pragma config(Sensor, in2,    BATERY_2_PORT,  sensorAnalog)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_6,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           MANIPULATOR,   tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port2,           RB_DRIVE,      tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           RF_DRIVE,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FLIP_LIFT,     tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port5,           LIFT_CLAW,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_6)
#pragma config(Motor,  port6,           T_CORE_LIFT,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           B_CORE_LIFT,   tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port8,           LB_DRIVE,      tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port9,           LF_DRIVE,      tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// for debugging purposes only does not effect the final program at all
#pragma DebuggerWindows("Motors")
#pragma DebuggerWindows("Sensors")
#pragma DebuggerWindows("debugStream")
#pragma DebuggerWindows("VexLCD")
#pragma DebuggerWindows("vexCompetitionControl")
#pragma DebuggerWindows("taskStatus")



#pragma platform(VEX2)
#pragma competitionControl(Competition)

// libs this is code i did not write
#include "Vex_Competition_Includes.c"
// #include "./lib/SmartMotorLib.c"


// external file includes
#include "./prototype/util.c"
#include "./prototype/joystick_defines_game.c"
#include "./prototype/pid.c"
#include "./prototype/gyro.c"
#include "./prototype/drive.c"
#include "./prototype/lift.c"
#include "./prototype/manipulator.c"
#include "./prototype/auton.c"
#include "./prototype/lcd.c"
#include "./prototype/operatorControl.c"



void pre_auton() {
  bStopTasksBetweenModes = true;

  clearDebugStream();

  // initialization of all the components of the bot
  lcdInit();
  driveInit();
  liftInit();
  maniplulatorInit();

  // allows the user to select autonomous
  selectAuton();

  clearLCD();

  string level;
  sprintf(level, "Primary %f%c", nImmediateBatteryLevel / 1000.0,'V');
  displayLCDCenteredString(0, level);

  sprintf(level, "pwr ex %f%c", ((float)SensorValue[ BATERY_2_PORT ] * 5.48),'V');
  displayLCDCenteredString(1, level);

}

task autonomous() {
  runAuton();

}



task usercontrol() {
  startTask(taskOPCdrive);
  startTask(taskOPCmanipulate);
  startTask(taskOPClift);

  /*
   * the while loop so the program does not end prematurely
   * the wait in order for the program to run all of its background tasks
   */
  while (true) {
    wait1Msec(20);
  }
}
