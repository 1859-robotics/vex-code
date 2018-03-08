#ifndef _PROTOTYPE_GYRO_
#define _PROTOTYPE_GYRO_

//ignore data within n standard deviations of no motion average
#define GYRO_STD_DEVS 2

//points or time in mSec that the gyro calibrates for
#define GYRO_CALIBRATION_POINTS 1

struct SGyroConfig{
	float m_fStdDev;
	float m_fAvg;
	float m_fVoltsPerDPS;
};

typedef struct {
	struct SGyroConfig m_config;
	float m_fAngle;
	int m_iPortNum;
  float rgfRaw[GYRO_CALIBRATION_POINTS];

} Gyro;


// requires: a motor index, the value to "set" the encoder to
// modifies: the encoder's pffset
// affects:  "sets" the encoder
void gyroInit(Gyro gyro, int iPortNum) {
	gyro.m_iPortNum = iPortNum;

	SensorType[iPortNum] = sensorNone;
	wait1Msec(1000);
	SensorType[iPortNum] = sensorGyro;
	wait1Msec(2000);

	// gyroCalibrate(gyro);
}




#endif
