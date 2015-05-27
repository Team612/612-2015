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
	static GamePad* driver; ///< Driver object
	static GamePad* gunner; ///< Gunner object

	void handleLatch(); ///< Called everytime
	void handleElevator();
private:
	bool toggleOpen; ///< Bool if elevator is open
	//bool hasDriven;
	bool isLatchPressed; ///< Bool if latch is pressed
	bool wasLatchPressed; ///< Bool if latch was pressed last "frame"
	//float val;
	//float preval;
};

#endif
