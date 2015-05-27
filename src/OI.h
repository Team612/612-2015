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
	static GamePad* driver; ///< @var Driver object
	static GamePad* gunner; ///< @var Gunner object

	void handleLatch(); ///< @fn Called everytime
	void handleElevator();
private:
	bool toggleOpen; ///< @var Bool if elevator is open
	//bool hasDriven;
	bool isLatchPressed; ///< @var Bool if latch is pressed
	bool wasLatchPressed; ///< @var Bool if latch was pressed last "frame"
	//float val;
	//float preval;
};

#endif
