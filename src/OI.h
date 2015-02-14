
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "GamePad.h"


class OI
{
public:
	OI();
	//Elevator Operator Buttons
	GamePad* driver;
	GamePad* gunner;
};

#endif
