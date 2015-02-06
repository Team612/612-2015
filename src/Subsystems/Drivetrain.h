#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <AnalogInput.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	//bool useIR = false;

	AnalogInput* ir;
	bool SwitchSensor(float distance); // Called in CheckSensor

public:
	Drivetrain(uint32_t talonchannel1,
					  uint32_t talonchannel2,
					  uint32_t talonchannel3,
					  uint32_t talonchannel4,
					  uint32_t infraredchannel);
	void InitDefaultCommand();

	//void CheckSensor(float distance);
	void move(float magnitude, float direction, float rotation);
	void stop();
	int16_t getir();

};

#endif
