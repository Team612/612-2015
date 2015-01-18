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
	MecanumDrivetrain(uint32_t talonchannel1,
					  uint32_t talonchannel2,
					  uint32_t talonchannel3,
					  uint32_t talonchannel4);
	void InitDefaultCommand();

	void move(float,float,float);

	void moveForwards();
	void moveBackwards();
	void moveLeft();
	void moveRight();

	void moveForwards(float rotationf);
	void moveBackwards(float rotationb);
	void moveLeft(float rotationl);
	void moveRight(float rotationr);

	void moveForwards(float directionf, float rotationf);
	void moveBackwards(float directionb, float rotationb);
	void moveLeft(float directionl, float rotationl);
	void moveRight(float directionr, float rotationr);

	void moveForwards(float speedf, float directionf, float rotationf);
	void moveBackwards(float speedb, float directionb, float rotationb);
	void moveLeft(float speedl, float directionl, float rotationl);
	void moveRight(float speedr, float directionr, float rotationr);

	void rotate(float angle);

	void stop();
};

#endif
