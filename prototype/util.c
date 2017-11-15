#ifndef _PROTOTYPE_UTIL_
#define _PROTOTYPE_UTIL_

#define sgn(in) in == 0 ? 0 : (in > 0 ? 1 : -1)


long nMotorEncoderOffsets[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

long gyroOffsets = 0;

long EncoderGetValue(tMotor index) {
  if(index < 0 || index >= kNumbOfTotalMotors) return 0;

  return (nMotorEncoder[index] - nMotorEncoderOffsets[index]);

}

void EncoderSetValue(tMotor index, float value) {
  if(index < 0 || index >= kNumbOfTotalMotors) return;

  nMotorEncoderOffsets[index] = nMotorEncoder[index] - value;
}
//
// long EncoderGetValue(tMotor index) {
//
//   return (SensorValue[GYRO_PORT] - gyroOffsets);
//
// }
//
// void gyroSet(float value) {
//   gyroOffsets = SensorValue[GYRO_PORT] - value;
//
// }

#endif
