#ifndef Latch_H
#define Latch_H

#include "RobotMap.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include <DoubleSolenoid.h>

class Latch: public CommandBase
{
public:;
	///Constructor for latch object
	///@param sol solenoid to do commands on
	///@param val value used by the solenoid
	Latch(DoubleSolenoid* sol, DoubleSolenoid::Value val);
	void Initialize(); ///<Initializer for solenoid
	void Execute(); ///<Run repeatedly
	bool IsFinished(); ///<Returns bool for if command is done
	void End(); ///< Called when the command is done
	void Interrupted(); ///<Called if command is interrupted

private:
	DoubleSolenoid* commandSol; ///<solenoid object (commands run on this)
	DoubleSolenoid::Value direction; ///< direction sent to solenoid
	Timer* timer; ///< Timer object
};

#endif
