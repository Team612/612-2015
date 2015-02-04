#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <../Subsystems/612Ultrasonic.h>
#include <../Subsystems/Infrared.h>

class MecanumDrivetrain: public Subsystem, public RobotDrive
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	SensorMaster sensor;
	Utrasonic612 ultra;
	Infrared612 infrared;


public:
	MecanumDrivetrain(uint32_t talonchannel1,
					  uint32_t talonchannel2,
					  uint32_t talonchannel3,
					  uint32_t talonchannel4);
	void InitDefaultCommand();

	void move(float magnitude, float direction, float rotation);
	void stop();

};

#endif
