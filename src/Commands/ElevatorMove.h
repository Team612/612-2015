#ifndef ElevatorMove_H
#define ElevatorMove_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "GamePad.h"

class ElevatorMove: public CommandBase
{
public:
	///Constructor
	///@param joy joystick used
	ElevatorMove(GamePad* joy);
	void Initialize(); ///<Initializer
	void Execute(); ///<Calls elevator move function with left joystick Y value
	bool IsFinished();
	void End(); ///<Stop elevator
	void Interrupted(); ///<Stop elevator
private:
	GamePad* joystick;
};

#endif
