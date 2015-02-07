#ifndef ROBOT_H
#define ROBOT_H
<<<<<<< HEAD
#include <Subsystems/Drivetrain.h>
=======
#include <Subsystems/DriveTrain.h>
>>>>>>> 2ab036a4697cde7d0c943de9a978246519b3694a

class Robot: public IterativeRobot
{
private:
	Command* autonomousCommand;
	LiveWindow* lw;
	Joystick* joystick;
	Talon* firstTalon;
	Talon* secondTalon;
	Talon* thirdTalon;
	//all acceleration is measured in meters per second squared
	BuiltInAccelerometer* speedgun; // Used for speedgun, a accelerometer
	double currentAcceleration = 0; // used for acceleration and accelerometer
	double maxAcceleration = 0; // used for highest acceleration during total run time
	Robot* robot;
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
	//612 Objects
<<<<<<< HEAD
	Drivetrain* robotDrive;
=======
	DriveTrain* robotDrive;
>>>>>>> 2ab036a4697cde7d0c943de9a978246519b3694a
};
#endif
