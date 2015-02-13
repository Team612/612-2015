#ifndef BreakerFlipper_H
#define BreakerFlipper_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/PowerBoard.h"

class BreakerFlipper: public CommandBase
{
private:
	Timer* timer;
	Encoder* encoder;

	const double ampLimit = 0.0; //TODO Fill in the right value
	const uint8_t channelCheck = 0; //TODO Fill in the right value
	const uint32_t encoderChannelA = 0; //TODO Fill in the right value
	const uint32_t encoderChannelB = 1; //TODO Fill in the right value

public:
	BreakerFlipper();
	void Initialize();
	void CheckMotor();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
