#include "OI.h"
#include "RobotMap.h"
#include "Commands/ElevatorUp.h"
#include "Commands/ElevatorDown.h"
#include "Commands/Drive.h"
#include "Commands/Latch.h"
#include "Commands/RedLEDOn.h"
#include "Commands/GreenLEDOn.h"
#include "GamePad.h"

GamePad* OI::driver = NULL;
GamePad* OI::gunner = NULL;

OI::OI()
{
	driver = new GamePad(DRIVER_JOY);
	gunner = new GamePad(GUNNER_JOY);

	gunner->ButtonX->WhenPressed(new Latch());
	driver->LeftShoulder->WhenPressed(new GreenLEDOn());
	driver->RightShoulder->WhenPressed(new RedLEDOn());
}
