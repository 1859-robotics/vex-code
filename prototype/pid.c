#ifndef _PROTOTYPE_PID_
#define _PROTOTYPE_PID_

#define MAX_SPEED 127
#define MIN_SPEED 40




typedef struct{

  float m_fKP;
	float m_fKI;
	float m_fKD;

  float m_fEpsilonInner;
	float m_fEpsilonOuter;

  float m_fSigma;

  float m_fLastValue;
	unsigned long m_uliLastTime;
  float m_fLastSetPoint;

} PID;

void pidInit (PID pid, float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter) {
	pid.m_fKP = fKP;
	pid.m_fKI = fKI;
	pid.m_fKD = fKD;
	pid.m_fEpsilonInner = fEpsilonInner;
	pid.m_fEpsilonOuter = fEpsilonOuter;
	pid.m_fSigma = 0;
	pid.m_fLastValue = 0;
	pid.m_uliLastTime = nPgmTime;
}

float pidCalculate (PID pid, float fSetPoint, float fProcessVariable) {
	float fDeltaTime = (float)(nPgmTime - pid.m_uliLastTime) / 1000.0;
	pid.m_uliLastTime = nPgmTime;

	float fDeltaPV = 0;
	if(fDeltaTime > 0)
		fDeltaPV = (fProcessVariable - pid.m_fLastValue) / fDeltaTime;

  pid.m_fLastValue = fProcessVariable;
	float fError = fSetPoint - fProcessVariable;

	if(fabs(fError) > pid.m_fEpsilonInner && fabs(fError) < pid.m_fEpsilonOuter)
		pid.m_fSigma += fError * fDeltaTime;

	if (fabs(fError) > pid.m_fEpsilonOuter)
		pid.m_fSigma = 0;

	float fOutput = fError * pid.m_fKP +
                  pid.m_fSigma * pid.m_fKI -
                  fDeltaPV * pid.m_fKD;

	return abs(fOutput) > MAX_SPEED ? MAX_SPEED * sgn(fOutput) :
         abs(fOutput) < MIN_SPEED ? MIN_SPEED * sgn(fOutput) : fOutput;
}


#endif
