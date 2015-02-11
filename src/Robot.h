#ifndef ROBOT_H
#define ROBOT_H

#include <Subsystems/Drivetrain.h>
#include "Commands/Drive.h"

class Robot: public IterativeRobot
{
private:

	//COMMAND
	Command* autonomousCommand;


	//DRIVETRAIN
	Drive* move;


	//LIVEWINDOW
	LiveWindow* lw;


	//JOYSTICK
	Joystick* joystick; // Used for joystick


	//TALON
	Talon* firstTalon;
	Talon* secondTalon;
	Talon* thirdTalon;


	//ACCELEROMETER
	// All acceleration is measured in meters per second squared
	BuiltInAccelerometer* speedgun; // Used for speedgun, a accelerometer
	double currentAcceleration = 0; // used for acceleration and accelerometer
	double maxAcceleration = 0; // used for highest acceleration during total run time

	Robot* robot;
public:
	//CONSTRUCTOR
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
	void TestPeriodic();
	void DisabledInit();
	void DisabledPeriodic();


	//612 FUNCTIONS
	void TestPulley();


	//612 OBJECTS
	enum ROBOT_STATUS{
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
