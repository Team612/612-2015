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
	int feedState;
	bool isPressed;
	bool wasPressed;
	GamePad* joyObj;
	CANTalon* leftFeedWheel;
	CANTalon* rightFeedWheel;
};

#endif
