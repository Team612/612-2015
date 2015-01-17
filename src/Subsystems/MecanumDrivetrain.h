#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>

class MecanumDrivetrain: public Subsystem, public RobotDrive
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	MecanumDrivetrain(uint8_t talonmod1, uint32_t talonchannel1,
					  uint8_t talonmod2, uint32_t talonchannel2,
					  uint8_t talonmod3, uint32_t talonchannel3,
					  uint8_t talonmod4, uint32_t talonchannel4);
	void InitDefaultCommand();
	void moveForwards(float rotationf);
	void moveBackwards(float rotationb);
	void moveLeft(float rotationl);
	void moveRight(float rotationr);
};

#endif
