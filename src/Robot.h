#ifndef ROBOT_H
#define ROBOT_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Drive.h"
#include "OI.h"
#include "Commands/Latch.h"
#include <Compressor.h>
#include "Commands/IntakeWheel.h"

class Robot: public IterativeRobot
{
private:

	Command* autonomousCommand; ///< @var command for autonomous (would have been command group, didn't get around to it)

	Drive* move; ///< @var DRIVETRAIN, used to move

	LiveWindow* lw; ///< @var LIVEWINDOW, not used
	//TALON
	//Talon* firstTalon;
	//Talon* secondTalon;
	//Talon* thirdTalon;

	
IntakeWheel* intake; ///< @var intake wheel for taking in bot, never used them (too heavy), so not used

	Compressor* compressor; ///< @var compressor
	// All acceleration is measured in meters per second squared
	BuiltInAccelerometer* speedgun; ///< @var accelerometer (horrible var name), detects change in momentum
	double currentAcceleration = 0; ///< @var used for acceleration and accelerometer, current acceleration
	double maxAcceleration = 0; ///< @var used for highest acceleration during total run time, prob never used

	Robot* robot; ///< @var THE ALL POWERFUL ROBOT

public:
	//CONSTRUCTOR
	void RobotInit(); ///< @fn Inits robot
	void AutonomousInit(); ///< @fn Inits autonomous
	void AutonomousPeriodic(); ///< @fn Even though we have command based robot, this is still required (but not used)
	void TeleopInit(); ///< @fn inits teleop (person operated)
	void TeleopPeriodic(); ///< @fn Inits teleop periodic (see autonomous periodic()
	void TestInit(); ///< @fn Inits test (for testing, not normally used)
	void TestPeriodic(); ///< @fn Inits test periodic (see autonomous periodic)
	void DisabledInit(); ///< @fn Inits disabled
	void DisabledPeriodic();///< @fn inits disabled periodic


	//612 FUNCTIONS
	void TestPulley(); ///< @fn Dunno what it does (never used)


	//612 OBJECTS
	enum ROBOT_STATUS{ ///< @var Enum for state of roboty
		NONE,
		ROBOTINIT,
		DISABLEDINIT,
		DISABLEDPERIODIC,
		AUTONOMOUSINIT,
		AUTONOMOUSPERIODIC,
		TELEOPINIT,
		TELEOPPERIODIC,
		TESTINIT,
		TESTPERIODIC
	};


	ROBOT_STATUS robot_status;
};
#endif
