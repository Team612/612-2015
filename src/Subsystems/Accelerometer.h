#ifndef SRC_SUBSYSTEMS_ACCELEROMETER_H_
#define SRC_SUBSYSTEMS_ACCELEROMETER_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Accelerometer: public Subsystem {
private:
	BuiltInAccelerometer accel;
public:
	Accelerometer();
	virtual ~Accelerometer();
	void InitDefaultCommand();
	// Other methods here (getValues, etc)
};

#endif /* SRC_SUBSYSTEMS_ACCELEROMETER_H_ */
