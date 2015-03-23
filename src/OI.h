#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "GamePad.h"
#include <Timer.h>

class OI
{
public:
	OI();
	//Elevator Operator Buttons
	static GamePad* driver;
	static GamePad* gunner;

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
