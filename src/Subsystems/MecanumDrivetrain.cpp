#include "MecanumDrivetrain.h"
#include "../RobotMap.h"
#include <Talon.h>

MecanumDrivetrain::MecanumDrivetrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4):
		Subsystem("MecanumDrivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))
{
	//import trackball or something? idk.
	/*
	 * You might have to do this on the real robot too
	 * drivetrain->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	 * drivetrain->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	 */
}

void MecanumDrivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void MecanumDrivetrain::move(float x, float y, float rotation)
{
	//after much testing, we discovered that mec drive works if we swap the rotation and x coordinate values. dont know why
	float temp = rotation; //create temporary variable to hold
	rotation = x; //put x into rotation
	x = temp; //now variables are fully swapped
	//now that they are swapped, plug them in correctly
	MecanumDrive_Cartesian(x,y,rotation); //for some reason, this works if x and rotation are swapped
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

void MecanumDrivetrain::stop()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
}
