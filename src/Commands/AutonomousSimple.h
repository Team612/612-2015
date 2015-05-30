#ifndef AUTONOMOUS_SIMPLE_H
#define AUTONOMOUS_SIMPLE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Robot.h"


class AutonomousSimple: public CommandBase
{
public:
	///Constructor
	///@param autoTime how long to go
	///@param autoSpeed how fast to go
	///@param sideways if the robot should go forward-back or left-right (true for forward-back)
	AutonomousSimple(float autoTime, float autoSpeed, bool sideways=false);

	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the command should end
	void End(); ///< The clean-up method when a  ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a  ends abruptly (from another event, such as a button release)
private:
	Timer* timer; ///<New timer object
	float autotime; ///< variable for how long the robot should drive
	float autospeed; ///< variable for how fast the robot should go
	bool side; ///< bool for if it's going sideways (true for forward-back)
};

#endif /* AUTONOMOUS_SIMPLE_H */
