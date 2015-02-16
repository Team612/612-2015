#ifndef ROBOT_H
#define ROBOT_H

#include <WPILib.h>
#include <Joystick.h>
#include <Compressor.h>
#include <CANTalon.h>

class Robot: public IterativeRobot
{
private:
	Joystick* joystick;
	//all acceleration is measured in meters per second squared
	// Used for speedgun, a accelerometer
	RobotDrive* drivetrain;
	Robot* robot;
	CANTalon* lift;
	Compressor* compressor;
	CANTalon* fl;
	CANTalon* fr;
	CANTalon* rl;
	CANTalon* rr;
	/*
	Encoder* frontLeft;
	Encoder* frontRight;
	Encoder* rearLeft;
	Encoder* rearRight;
	*/
public:
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
	void TestPeriodic();
	void DisabledInit();
	void DisabledPeriodic();

	//612 functions
	void TestPulley();
	float getInput(uint32_t);
	//612 Objects
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
