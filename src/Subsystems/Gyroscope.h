#ifndef SRC_SUBSYSTEMS_GYROSCOPE_H_
#define SRC_SUBSYSTEMS_GYROSCOPE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Gyroscope: public Subsystem
{
private:
	Gyro* gyro;
public:
	Gyroscope();
	virtual ~Gyroscope();
	void InitDefaultCommand();

	// Other methods here
	double getRate();
	float getAngle();

	void reset();
};

#endif /* SRC_SUBSYSTEMS_GYROSCOPE_H_ */
