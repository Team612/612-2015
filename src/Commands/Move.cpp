#include "Move.h"

Move::Move(Robot* r, Joystick* j)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
	robot = r;
	joystick = j;
}

Move::~Move()
{
	delete robot;
	delete joystick;
}

// Called just before this Command runs the first time
void Move::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Move::Execute()
{
	//Get the values from the joystick
	float x = joystick->GetRawAxis(LEFT_X);
	float y = joystick->GetRawAxis(LEFT_Y);
	float rotation = joystick->GetRawAxis(RIGHT_X);

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

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished()
{
	return false; //should always be false
}

// Called once after isFinished returns true
void Move::End()
{
	drivetrain->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted()
{
	drivetrain->stop();
}
