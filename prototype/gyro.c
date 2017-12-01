#ifndef _PROTOTYPE_GYRO_
#define _PROTOTYPE_GYRO_

//ignore data within n standard deviations of no motion average
#define GYRO_STD_DEVS 2

//points or time in mSec that the gyro calibrates for
#define GYRO_CALIBRATION_POINTS 2000

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


void gyroCalibrate(Gyro gyro) {
	float fRawAverage = 0.0;
	float fStdDev = 0.0;


	for(int i = 0; i < GYRO_CALIBRATION_POINTS; ++i) {
		float fRaw = SensorValue (gyro.m_iPortNum);
		fRawAverage += fRaw;
		gyro.rgfRaw[i] = fRaw;
		delay(1);
	}

  fRawAverage /= GYRO_CALIBRATION_POINTS;
	gyro.m_config.m_fAvg = fRawAverage;


  for (int i = 0; i < GYRO_CALIBRATION_POINTS; ++i) {
    fStdDev += fabs(fRawAverage - gyro.rgfRaw[i]);
  }

  fStdDev /= (float) GYRO_CALIBRATION_POINTS;

  gyro.m_config.m_fStdDev = fStdDev;


  gyro.m_config.m_fVoltsPerDPS = (0.0011/1.71625741) * (fRawAverage * 5 / 4095);
}

void gyroInit(Gyro gyro, int iPortNum) {
	gyro.m_iPortNum = iPortNum;
	gyroCalibrate(gyro);
}

float gyroGetRate(Gyro gyro) {
	float fGyroRead = SensorValue(gyro.m_iPortNum);

	//Difference from zero-rate value or the average calibration read
	float fGyroDiff = fGyroRead - gyro.m_config.m_fAvg;

	//Difference fro zero-rate value, in volts
	float fGyroVoltage = fGyroDiff * 5 / 4095;

	if(fabs(fGyroDiff) > GYRO_STD_DEVS * gyro.m_config.m_fStdDev) {
		return fGyroVoltage / gyro.m_config.m_fVoltsPerDPS;
  }
	return 0;
}


#endif
