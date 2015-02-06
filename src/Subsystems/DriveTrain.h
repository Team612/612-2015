#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <Subsystems/Infrared612.h>
#include "Ultrasonic612.h"

class DriveTrain: public Subsystem, public RobotDrive
{
private:
	Ultrasonic612 ultra;
	Infrared612 infrared;
	bool useIR = false;

	bool SwitchSensor(float distance); // Called in CheckSensor

public:
	DriveTrain(uint32_t talonchannel1,
					  uint32_t talonchannel2,
					  uint32_t talonchannel3,
					  uint32_t talonchannel4);
	void InitDefaultCommand();

	void CheckSensor(float distance);
	void move(float magnitude, float direction, float rotation);
	void stop();

};

#endif
