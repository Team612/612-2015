#ifndef ActivateSolenoid_H
#define ActivateSolenoid_H

#include "../CommandBase.h"
#include "WPILib.h"

class ActivateSolenoid: public CommandBase
{
private:
	Timer* timer; ///<Timer object
	uint32_t targetTime; ///<total time value (how long)
	DoubleSolenoid* solenoid; ///<solenoid object
	DoubleSolenoid::Value solenoidState; ///< state of solenoid
public:
	///Constructor
	///@param solenoid_ solenoid object to use
	///@param value value to be passed to solenoid
	///@param time how long to activate solenoid
	ActivateSolenoid(DoubleSolenoid* solenoid_, DoubleSolenoid::Value value, uint32_t time);
	void Initialize(); ///<starts timer
	void Execute(); ///<sets solenoid to solenoid state
	bool IsFinished(); ///<check if time's done
	void End(); ///<if the command is finished, turn off solenoid
	void Interrupted(); ///<if the command is interrupted, turn off solenoid
};

#endif
