#ifndef IntakeWheel_H
#define IntakeWheel_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "GamePad.h"

class IntakeWheel: public CommandBase
{
public:
	IntakeWheel(GamePad* joystick);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	GamePad* joyObj;
	CANTalon* leftFeedWheel;
	CANTalon* rightFeedWheel;
};

#endif
