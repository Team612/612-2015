#ifndef SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_
#define SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_

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

#endif /* SRC_SUBSYSTEMS_DRIVEACCELEROMETER_H_ */
