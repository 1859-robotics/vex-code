#ifndef _PROTOTYPE_UTIL_
#define _PROTOTYPE_UTIL_

// if the input is positive then it returns a 1
// if the input is 0 then it returns a 0
// if the input is negative it returns a -1
#define sgn(in) (in == 0 ? 0 : (in > 0 ? 1 : -1))

#define sizeofArr(a) (sizeof(a)/sizeof(a[0]))

// Array of ints as a struct
// Because robotC is bugged to hell and back the byte
// memeber has to be there or it won't work.
typedef struct {
  string arr[255];
  byte derps;
} tStringArray;


// motor offsets to simulate zeroing an encoder
long nMotorEncoderOffsets[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// requires: a motor index
// modifies: null
// affects:  returns the encoder's value based on the encoder offsets
long EncoderGetValue(tMotor index) {
  if(index < 0 || index >= kNumbOfTotalMotors) return 0;

  return (nMotorEncoder[index] - nMotorEncoderOffsets[index]);

}

// requires: a motor index, the value to "set" the encoder to
// modifies: the encoder's pffset
// affects:  "sets" the encoder
void EncoderSetValue(tMotor index, float value) {
  if(index < 0 || index >= kNumbOfTotalMotors) return;

  nMotorEncoderOffsets[index] = nMotorEncoder[index] - value;
}

/*******************************************************************************
 * in the begining of this season we were                                      *
 * using jPearman's smart motor library                                        *
 * however we tested and while it did increase the time until it stalls        *
 * the library was too processor heavy and made                                *
 * both our auton and driver control too innaccurate                           *
 * this is a proxy without the functionallity to effeciently migrate           *
 * out of using the library                                                    *
 *******************************************************************************/
void SetMotor(unsigned int m, int spd, bool E = false) {
  motor[m] = spd;
}



#endif
