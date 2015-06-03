#ifndef Autonomous_H
#define Autonomous_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <cmath>
#include "Drive.h"

class Autonomous: public CommandBase
{
public:
	enum AutoMode {NO_AUTO, FORWARD_PUSH, SIDEWAYS_PUSH, ONE_BIN_PUSHSTACK, ONE_BIN_CARRYSTACK, TWO_BIN_PUSHSTACK, TWO_BIN_CARRYSTACK, THREE_BIN_PUSHSTACK, THREE_BIN_CARRYSTACK};
	Autonomous(float autoDist, float autoSpeed, AutoMode autoMode);
	~Autonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float autodist;
	float autospeed;
	AutoMode automode;
	bool isfinished;
};

#endif
