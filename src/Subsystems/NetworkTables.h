#ifndef SRC_SUBSYSTEMS_ELEVATOR_H_
#define SRC_SUBSYSTEMS_ELEVATOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Elevator : public Subsystem {
private:
	Talon* talon;
	DigitalInput* topSwitch;
	DigitalInput* bottomSwitch;
	Encoder* encoder;
public:
	Elevator();
	virtual ~Elevator();
	void move(float magnitude);
	void stop();
	void InitDefaultCommand();
	Encoder* getEncoder();
};

#endif /* SRC_SUBSYSTEMS_ELEVATOR_H_ */
