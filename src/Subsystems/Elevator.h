#ifndef SRC_SUBSYSTEMS_ELEVATOR_H_
#define SRC_SUBSYSTEMS_ELEVATOR_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator : public Subsystem {
private:
	Talon* talon;
public:
	Elevator();
	virtual ~Elevator();
	void move(float magnitude);
	void stop();
};

#endif /* SRC_SUBSYSTEMS_ELEVATOR_H_ */
