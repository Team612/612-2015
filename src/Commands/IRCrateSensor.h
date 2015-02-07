#ifndef IR_CRATE_SENSOR_H
#define IR_CRATE_SENSOR_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Robot.h"


class IRCrateSensor: public CommandBase
{
public:
	IRCrateSensor(); ///< The constructor for the Example
	void Initialize(); ///< Runs after the constructor
	void Execute(); ///< This method is called repeatedly 
	bool IsFinished(); ///< This method contains the logic of when the  should end
	void End(); ///< The clean-up method when a  ends gracefully (IsFinished returns true)
	void Interrupted(); ///< The clean-up method when a  ends abruptly (from another event, such as a button release)
private:
};

#endif
