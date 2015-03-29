#ifndef MOVETOTOTE_H_
#define MOVETOTOTE_H_

#include "../CommandBase.h"
#include "WPILib.h"
#include <cmath>

class MoveToTote: public CommandBase
{
public:
	MoveToTote(uint32_t targetDistance); //Moves within targetDistance of tote (measured in feet)
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool success = false;
	bool failure = false;

	bool aligned = false;
	bool atTote = false;

	uint32_t targetDist;

	void navigate();
	void processMovement();

	bool camerasWorking();
	bool dataAccurate();

	float calculateAlignment();

	static bool inRange(int a, int b, uint32_t range);
};

#endif /* LATCH_CPP_SRC_COMMANDS_MOVETOTOTE_H_ */
