#ifndef LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_
#define LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>
#include <TalonSRX.h>

class Elevator : public Subsystem {
private:
	TalonSRX* talon;
	DigitalInput* topSwitch;
	DigitalInput* bottomSwitch;
	Encoder* encoder;
	DoubleSolenoid* firstsolenoid;
	DoubleSolenoid* secondsolenoid;
public:
	Elevator();
	virtual ~Elevator();
	void move(float magnitude);
	void stop();
	void InitDefaultCommand();
	Encoder* getEncoder();
	void firstSolClose();
	void firstSolOpen();
	void secondSolClose();
	void secondSolOpen();
};

#endif /* LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_ */
