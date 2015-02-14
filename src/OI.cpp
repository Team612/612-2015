#include "OI.h"
#include "RobotMap.h"
#include "Commands/ElevatorUp.h"
#include "Commands/ElevatorDown.h"
#include "Commands/Drive.h"

OI::OI()
{
	driver = new GamePad(1);
	gunner = new GamePad(2);
}
