#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <AnalogInput.h>
#include <Ultrasonic.h>

class DriveTrain: public Subsystem, public RobotDrive
{
private:
	Ultrasonic* ultra;
	AnalogInput* infrared;
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
