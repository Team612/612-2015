#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drivetrain();
	void InitDefaultCommand();

	void move(float magnitude, float direction, float rotation);
	void stop();
};

#endif
