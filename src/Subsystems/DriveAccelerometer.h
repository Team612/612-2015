#ifndef LATCH_CPP_SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_
#define LATCH_CPP_SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class DriveAccelerometer: public Subsystem
{
private:
	BuiltInAccelerometer* accel;
public:
	DriveAccelerometer();
	virtual ~DriveAccelerometer();
	void InitDefaultCommand();
	// Other methods here (getValues, etc)
	double GetX();
	double GetY();
	double GetZ();
};

#endif /* LATCH_CPP_SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_ */
