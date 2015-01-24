#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include <cstdio>
#include <Joystick.h>
#include <Talon.h>
#include "Subsystems/MecanumDrivetrain.h"
#include "Robot.h"
#include "RobotMap.h"


void Robot::RobotInit()
{
	CommandBase::init();
	autonomousCommand = new ExampleCommand();
	lw = LiveWindow::GetInstance();
	robotDrive = new MecanumDrivetrain(MOTOR_LF,MOTOR_LR,MOTOR_RF,MOTOR_RR);//The 4 talons
	joystick = new Joystick(1);//Right hand joystick
	speedgun = new BuiltInAccelerometer(); // New accelerometer called speedgun
	robot = this;
}

void Robot::DisabledInit()
{

}

void DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();

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
		float val = joystick->GetRawAxis(5);//Takes input from joystick
		float leftYAxis = joystick->GetRawAxis(2);
		/*firstTalon->Set(val);//Gives joystick input to first talon
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

}
void Robot::TestPeriodic()
{
	lw->Run();
	float val = joystick->GetRawAxis(5);//Takes input from joystick
	firstTalon->Set(val);//Gives joystick input to first talon
	secondTalon->Set(val);
	
}


START_ROBOT_CLASS(Robot);

