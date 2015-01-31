#ifndef SRC_SUBSYSTEMS_GYRO_H_
#define SRC_SUBSYSTEMS_GYRO_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Gyroscope: public Subsystem
{
private:
	Gyro gyro;
public:
	Gyroscope();
	virtual ~Gyroscope();
	void InitDefaultCommand();
	// Other methods here
};

#endif /* SRC_SUBSYSTEMS_GYRO_H_ */
