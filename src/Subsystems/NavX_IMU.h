#ifndef NavX_IMU_H
#define NavX_IMU_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../include/AHRS.h"

class NavX_IMU: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AHRS* navX;
	//SerialPort* middleManPort;
public:
	NavX_IMU();
	void InitDefaultCommand();
	bool IsRobotMoving(); //mainly to test if this thing is working
};

#endif
