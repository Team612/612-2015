#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	Encoder* encoderLF;
	Encoder* encoderLR;
	Encoder* encoderRF;
	Encoder* encoderRR;
public:
	Drivetrain();
	void InitDefaultCommand();
	void move(float x, float y, float rotation);
	void stop();
	void moveTank(float l, float r);

	Encoder* getLFEncoder();
	Encoder* getLREncoder();
	Encoder* getRFEncoder();
	Encoder* getRREncoder();
};

#endif
