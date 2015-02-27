#ifndef AUTONOMOUS_SIMPLE_H
#define AUTONOMOUS_SIMPLE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Robot.h"


class AutonomousSimple: public CommandBase
{
public:
	AutonomousSimple(float autoTime, float autoSpeed); ///< The constructor for the Example
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the  should end
	void End(); ///< The clean-up method when a  ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a  ends abruptly (from another event, such as a button release)
private:
	Timer* timer; //New timer object
	float autotime;
	float autospeed;
};

#endif /* AUTONOMOUS_SIMPLE_H */
