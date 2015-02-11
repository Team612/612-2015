#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include <cstdio>
#include <Joystick.h>
#include "Subsystems/Drivetrain.h"
//#include <Talon.h>
#include "Commands/AutonomousSimple.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Commands/Drive.h"


void Robot::RobotInit()
{
	robot_status = ROBOTINIT;
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	joystick = new Joystick(DRIVER_JOY);//Right hand joystick
	speedgun = new BuiltInAccelerometer(); // New accelerometer called speedgun
	robot = this;
}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT;
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT;
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC)
		robot_status = AUTONOMOUSPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	robot_status = TELEOPINIT;
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	if (robot_status != TELEOPPERIODIC)
		robot_status = TELEOPPERIODIC;
	Scheduler::GetInstance()->Run();
	//drivetrain->move(joystick->GetRawAxis(LEFT_X),joystick->GetRawAxis(LEFT_Y),joystick->GetRawAxis(RIGHT_X));
	static unsigned int TimeChecked = 0;
	TimeChecked++;
	currentAcceleration = (speedgun -> GetY())*9.806; // covert from g force to acceleration
	if (currentAcceleration > maxAcceleration)// check to see if currentAcceleration is bigger that maxAcceleration. if yes, set maxAcceleration to currentAcceleration
	{
		maxAcceleration = currentAcceleration; //set the values
	}
	if (TimeChecked == 30) //print every half second
	{
		lw->Run();

		/*float val = joystick->GetRawAxis(5);//Takes input from joystick
		float leftYAxis = joystick->GetRawAxis(2);
		firstTalon->Set(val);//Gives joystick input to first talon
		secondTalon->Set(val);
		thirdTalon->Set(leftYAxis);*/
	}

	printf("Raw G-force on Y-axis is %f meters per second per second \n", speedgun -> GetY()); //prints raw g-force
	printf("Acceleration is %f meters per second per second \n", currentAcceleration); //prints currentAcceleration
	printf("Max acceleration is %f meters per second per second \n", maxAcceleration); //prints maxAcceleration
	TimeChecked = 0;

}

void Robot::TestInit()
{
	robot_status = TESTINIT;
}
void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC)
		robot_status = TESTPERIODIC;
	lw->Run();
	float val = joystick->GetRawAxis(5);//Takes input from joystick
	firstTalon->Set(val);//Gives joystick input to first talon
	secondTalon->Set(val);
	
}


START_ROBOT_CLASS(Robot);

