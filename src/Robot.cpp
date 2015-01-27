#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Move.h"
#include "CommandBase.h"
#include "Robot.h"
#include "RobotMap.h"

void Robot::RobotInit()
{
	CommandBase::init();
	lw = LiveWindow::GetInstance();
	joy = new Joystick(0);

	talon0 = new Talon(0);
	talon1 = new Talon(1);
	talon2 = new Talon(2);
	talon3 = new Talon(3);

	drivetrain = new RobotDrive(talon1, talon2, talon0, talon3);
	//Remember to do this, and it must come after the drivetrain constructor call
	drivetrain->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	drivetrain->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleop Initialized");
}

void Robot::TeleopPeriodic()
{
	printf("Teleop Periodic start");
	//moveCommand->Start();
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
//	lw->Run();

}

float Robot::getValues(int axis)
{
	float val = joy->GetRawAxis(axis);
	if (axis < TOLORANCE && axis > -TOLORANCE)
	{
		return 0.0f;
	}
	else
	{
		if (axis == 0 || axis == 4)
		{
			return -val*THROTTLE;
		}
		else
		{
			return val*THROTTLE;
		}
	}
}

void Robot::MecDrive(float x, float y, float rotation)
{
	//after much testing, we discovered that mec drive works if we swap the rotation and x coordinate values. dont know why
	float temp = rotation; //create temporary variable to hold
	rotation = x; //put x into rotation
	x = temp; //now variables are fully swapped
	//now that they are swapped, plug them in correctly
	drivetrain->MecanumDrive_Cartesian(x,y,rotation); //for some reason, this works if x and rotation are swapped
	//in case we need to debug
	#ifdef DEBUG
		static int count = 0;
		if (count % 30 == 0)
		{
			std::printf("X = %f\t Y = %f\tR = %f\n\n", x, y,rotation);
		}
		count++;
	#endif
}

START_ROBOT_CLASS(Robot);

