#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include <cstdio>

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow* lw;
	RobotDrive* robotDrive;
	Joystick* joystick;
	//all acceleration is measured in meters per second squared
	BuiltInAccelerometer* speedgun; // Used for speedgun, a accelerometer
	double currentAcceleration = 0; // used for acceleration and accelerometer
	double maxAcceleration = 0; // used for highest acceleration during total run time

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		robotDrive = new RobotDrive(new Talon(1), new Talon(2), new Talon(3), new Talon(4));
		joystick = new Joystick(1);
		speedgun = new BuiltInAccelerometer(); // New accelerometer called speedgun

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		robotDrive->ArcadeDrive(joystick);
		static unsigned int TimeChecked = 0;
		TimeChecked++;
		currentAcceleration = (speedgun -> GetY())*9.806; // covert from g force to acceleration
		if (currentAcceleration > maxAcceleration)// check to see if currentAcceleration is bigger that maxAcceleration. if yes, set maxAcceleration to currentAcceleration
		{
			maxAcceleration = currentAcceleration; //set the values
		}
		if (TimeChecked == 30) //print every half second
		{
			printf("Raw G-force on Y-axis is %f meters per second per second \n", speedgun -> GetY()); //prints raw g-force
			printf("Acceleration is %f meters per second per second \n", currentAcceleration); //prints currentAcceleration
			printf("Max acceleration is %f meters per second per second \n", maxAcceleration); //prints maxAcceleration
			TimeChecked = 0;
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

