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
	robot_status = ROBOTINIT; // Makes the status equal ROBOTINIT
	CommandBase::init(); // Constructor for CommandBase
	lw = LiveWindow::GetInstance();
	joystick = new Joystick(DRIVER_JOY); // Construct left hand joystick
	speedgun = new BuiltInAccelerometer(); // Construct new accelerometer called speedgun
	robot = this;
	prefs = Preferences::GetInstance();
}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT; // Makes the status equal DISABLEDINIT
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT; // Makes the status equal AUTONOMOUSINIT
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC) // Makes the status equal AUTONOMOUSPERIODIC
		robot_status = AUTONOMOUSPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	robot_status = TELEOPINIT; // Makes the status equal TELEOPINIT
	/*
	 * This makes sure that the autonomous stops running when
	 * teleop starts running. If you want the autonomous to
	 * continue until interrupted by another command, remove
	 * this line or comment it out.
	 */
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	move = new Drive(joystick);
	move->Start();
}

void Robot::TeleopPeriodic()
{
	if (robot_status != TELEOPPERIODIC) // Makes the status equal TELEOPPERIODIC
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
	if (TimeChecked == 30) //print every half second for debug
	{
		lw->Run();

		/*float val = joystick->GetRawAxis(5);//Takes input from joystick
		float leftYAxis = joystick->GetRawAxis(2);
		firstTalon->Set(val);//Gives joystick input to first talon
		secondTalon->Set(val);
		thirdTalon->Set(leftYAxis);*/

		printf("Raw G-force on Y-axis is %f meters per second per second \n", speedgun -> GetY()); //prints raw g-force
		printf("Acceleration is %f meters per second per second \n", currentAcceleration); //prints currentAcceleration
		printf("Max acceleration is %f meters per second per second \n", maxAcceleration); //prints maxAcceleration
	}
	TimeChecked = 0;

}

void Robot::TestInit()
{
	robot_status = TESTINIT;
	/*
	float P = 1.0f;
	float I = 0.0f;
	float D = 0.0f;
	//zack = new CANTalon612(5,0,1,P,I,D,false,true);
	*/
}

void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC) // Makes the status equal TESTPERIODIC
		robot_status = TESTPERIODIC;
	lw->Run();
	/*
	float val = joystick->GetRawAxis(5); //Takes input from joystick
	firstTalon->Set(val); //Gives joystick input to first talon
	secondTalon->Set(val);
	*/
	//zack->Set(val);
}


START_ROBOT_CLASS(Robot);

