/*
 * Robot.h
 *
 *  Created on: Jan 26, 2015
 *      Author: zachary
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	RobotDrive* drivetrain;
	Joystick* joy;
	Talon* talon0;
	Talon* talon1;
	Talon* talon2; //invert
	Talon* talon3; //invert
	Move* moveCommand = new Move();
public:
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
	void TestPeriodic();
};

#endif /* SRC_ROBOT_H_ */
