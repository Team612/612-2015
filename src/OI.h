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
	static GamePad* driver; ///< driver object
	static GamePad* gunner; ///< gunner object
	/// Toggle latch state
	/// Run every "frame", if latch button is pressed
	/// And it wasn't pressed last frame, toggle latch
	void handleLatch();
	/// Moves elevator
	/// Toggles elevator between moving up/down/stopped
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
