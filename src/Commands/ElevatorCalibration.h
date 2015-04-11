#ifndef ElevatorCalibration_H
#define ElevatorCalibration_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "GamePad.h"

class Timer;

class ElevatorCalibration: public CommandBase
{
private:
	Timer* time;
	double nowTime;
	std::vector<float>* valVectorBottom;
	std::vector<float>* valVectorTop;
	Preferences* prefs;
	float bottomSum;
	float topSum;
	float ELEV_CALIBRATION_TOLERANCE;
	bool isFinished;
	bool stage1;
public:
	ElevatorCalibration();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
