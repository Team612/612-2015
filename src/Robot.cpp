#include "WPILib.h"
#include <Joystick.h>
#include "Robot.h"
#include "RobotMap.h"


void Robot::RobotInit()
{
	robot_status = ROBOTINIT;
	joystick = new Joystick(DRIVER_JOY);//Right hand joystick
	robot = this;

	//drivetrain
	fl = new CANTalon(MOTOR_FL);
	rl = new CANTalon(MOTOR_RL);
	fr = new CANTalon(MOTOR_FR);
	rr = new CANTalon(MOTOR_RR);

	drivetrain = new RobotDrive(fl,rl,fr,rr);
	drivetrain->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drivetrain->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	drivetrain->SetSafetyEnabled(false);


	lift = new CANTalon(6);
	compressor = new Compressor(PCM);
	/*
	frontLeft = new Encoder(ENCODER_FL_A, ENCODER_FL_B);
	rearLeft = new Encoder(ENCODER_RL_A, ENCODER_RL_B);
	frontRight = new Encoder(ENCODER_FR_A, ENCODER_FR_B);
	rearRight = new Encoder(ENCODER_RR_A, ENCODER_RR_B);
	*/
}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT;
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT;
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC)
		robot_status = AUTONOMOUSPERIODIC;
}

void Robot::TeleopInit()
{
	robot_status = TELEOPINIT;
	drivetrain->MecanumDrive_Cartesian(0,0,0);
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
}

void Robot::TeleopPeriodic()
{
	compressor->Start();
	if (robot_status != TELEOPPERIODIC)
		robot_status = TELEOPPERIODIC;
	float x = getInput(LEFT_X);
	float y = getInput(LEFT_Y);
	float rotation = getInput(RIGHT_X);
	drivetrain->MecanumDrive_Cartesian(x,y,rotation);
	float winch = getInput(RIGHT_Y);
	lift->Set(winch);
	static unsigned int count = 0;
	if (count % 30 == 0)
	{
		std::printf("Front Left = %f", (float)fl->GetPosition());
		std::printf("Front Right = %f", (float)fr->GetPosition());
		std::printf("Rear Left = %f", (float)rl->GetPosition());
		std::printf("Rear Right = %f", (float)rr->GetPosition());
	}
	count++;

}

void Robot::TestInit()
{
	robot_status = TESTINIT;
}
void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC)
		robot_status = TESTPERIODIC;
}

float Robot::getInput(uint32_t joy)
{
	float val = joystick->GetRawAxis(joy);
	if (val > DEADZONE || val < -1*DEADZONE)
		return val;
	else
		return 0.0f;
}


START_ROBOT_CLASS(Robot);

