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

	Command* autonomousCommand; ///< command fotus (would have been command group, didn't get around to it)

	Drive* move; ///< DRIVETRAIN object, used to move

	LiveWindow* lw; ///< LIVEWINDOW object, not used
	//TALON
	//Talon* firstTalon;
	//Talon* secondTalon;
	//Talon* thirdTalon;

	
IntakeWheel* intake; ///< intake wheel for taking in bot, never used them (too heavy), so not used

	Compressor* compressor; ///< compressor (pneumatics)
	// All acceleration is measured in meters per second squared
	BuiltInAccelerometer* speedgun; ///< accelerometer (horrible var name), detects change in momentum
	double currentAcceleration = 0; ///< used for acceleration and accelerometer, current acceleration
	double maxAcceleration = 0; ///< used for highest acceleration during total run time, prob never used

	Robot* robot; ///< THE ALL POWERFUL ROBOT OBJECT

public:
	//CONSTRUCTORS
	void RobotInit(); ///< Inits robot
	void AutonomousInit(); ///< Inits autonomous
	void AutonomousPeriodic(); ///< Even though we have command based robot, this is still required (but not used)
	void TeleopInit(); ///< inits teleop (person operated)
	void TeleopPeriodic(); ///< Inits teleop periodic (see autonomous periodic()
	void TestInit(); ///< Inits test (for testing, not normally used)
	void TestPeriodic(); ///< Inits test periodic (see autonomous periodic)
	void DisabledInit(); ///< Inits disabled
	void DisabledPeriodic();///< inits disabled periodic


	//612 FUNCTIONS
	void TestPulley(); ///< Dunno what it does (never used)


	//612 OBJECTS
	enum ROBOT_STATUS{ ///< Enum for state of roboty
		NONE, ///< Enum value of off/no state
		ROBOTINIT, ///< Robot init but no specific mode
		DISABLEDINIT, ///< Inits disabled mode (before periodic)
		DISABLEDPERIODIC, ///< In disabled periodic
		AUTONOMOUSINIT, ///< In autonomous (before periodic)
		AUTONOMOUSPERIODIC, ///< In autonomous periodic
		TELEOPINIT, ///< In teleop (before periodic)
		TELEOPPERIODIC, ///< In teleop periodic
		TESTINIT, ///< In test (before init)
		TESTPERIODIC ///< In test periodic
	};


	ROBOT_STATUS robot_status; ///<Var that holds current state of robot (from ROBOT_STATUS enum)
};
#endif