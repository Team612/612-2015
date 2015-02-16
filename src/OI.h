
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "GamePad.h"
#include "RobotMap.h"


class OI
{
public:
	OI();
	//Elevator Operator Buttons
	static GamePad* driver;
	static GamePad* gunner;
};

#endif
