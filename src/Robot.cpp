#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include <cstdio>
#include <Joystick.h>
#include "Subsystems/Drivetrain.h"
#include <Talon.h>
#include "Commands/AutonomousSimple.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Commands/Drive.h"


void Robot::RobotInit()
{
	printf("Robotinit1\n");
	robot_status = ROBOTINIT; // Makes the status equal ROBOTINIT
	printf("Robotinit2\n");
	CommandBase::init(); // Constructor for CommandBase
	printf("Robotinit3\n");
	lw = LiveWindow::GetInstance();
	printf("Robotinit4\n");
	speedgun = new BuiltInAccelerometer(); // New accelerometer called speedgun
	printf("Robotinit5\n");
	move = new Drive(CommandBase::oi->driver);
	printf("Robotinit6\n");
	robot = this;
	printf("Robotinit7\n");
	compressor = new Compressor(PCM);
	printf("Robotinit8\n");

	/// CLOSER PLATFORM
	autonomousCommand = new AutonomousSimple(3.5f, 0.4f);//Initializes simple autonomous program with
														 //time in seconds to move forward, and motor velocity
	                                                                                                                         //between 0 and 1.
	/// FARTHER PLATFORM
	//autonomousCommand = new AutonomousSimple(5.5f, 0.4f);

	/// NO AUTO
	//autonomousCommand = new AutonomousSimple(0.0f, 0.0f);

	//autonomousCommand = new Autonomous();

	CameraServer::GetInstance()->SetQuality(50);
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	std::printf("Starting camera server\n");
}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT; // Makes the status equal DISABLEDINIT
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
	//Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT; // Makes the status equal AUTONOMOUSINIT
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
	compressor->Start();
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC) // Makes the status equal AUTONOMOUSPERIODIC
		robot_status = AUTONOMOUSPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleopinit\n");
	robot_status = TELEOPINIT; // Makes the status equal TELEOPINIT
	/*
	 * This makes sure that the autonomous stops running when
	 * teleop starts running. If you want the autonomous to
	 * continue until interrupted by another command, remove
	 * this line or comment it out.
	 */
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	move->Start();
	compressor->Start();

	//Driveteam's stuff
	CommandBase::oi->handleLatch();
	CommandBase::oi->handleElevator();
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
	CommandBase::oi->handleLatch();
	//CommandBase::oi->handleElevator();
}

void Robot::TestInit()
{
	robot_status = TESTINIT; // Makes the status equal TESTINIT
	printf("lel what are you even doing here scrub?\n");
}
void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC) // Makes the status equal TESTPERIODIC
		robot_status = TESTPERIODIC;
	lw->Run();
	//float val = joystick->GetRawAxis(5); //Takes input from joystick
	//firstTalon->Set(val); //Gives joystick input to first talon
	//secondTalon->Set(val);
	
}


START_ROBOT_CLASS(Robot);

