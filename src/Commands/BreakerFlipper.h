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
	PowerBoard* powerboard;
	TalonSRX* talonsrx;

	const double ampLimit = 0.0; //TODO Fill in the right value. Used for the difference of the previous amp to the current amp. if it is too low, then it will check the motor.
	const double timeLimit = 0.0; //TODO Fill in the right value. Used for detecting if the motor will move.
	const uint8_t channelCheck = 0; //TODO Fill in the right value. Used for the powerboard channel for the motor
	const uint32_t encoderChannelA = 0; //TODO Fill in the right value. Used for the encoder channel a
	const uint32_t encoderChannelB = 1; //TODO Fill in the right value. Used for the encoder channel b
	double previousAmp = 0.0; //Used as a buffer variable


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
