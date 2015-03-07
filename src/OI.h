#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Lib612/Lib612.h"
#include <Timer.h>

class OI
{
public:
	OI();
	//Elevator Operator Buttons
	static Lib612::GamePad* driver;
	static Lib612::GamePad* gunner;

	void handleLatch();
	void handleElevator();
private:
	bool toggleOpen;
	//bool hasDriven;
	bool isLatchPressed;
	bool wasLatchPressed;
	//float val;
	//float preval;
};

#endif
