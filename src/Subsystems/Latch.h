#ifndef Latch_H
#define Latch_H

#include "WPILib.h"
#include <Solenoid.h>
#include <Relay.h>

class Latch: public Subsystem
{
private:
    // I think you're going to need a private variable.
    // The variable type would be either a Relay or Solenoid
    // see https://chantilly612code.github.io/612-2015/classRelay.html
    // see https://chantilly612code.github.io/612-2015/classSolenoid.html
	Solenoid solenoid;
	Relay relay;

public:
	Latch();
	void Open();
	void Close();
};

#endif /* LATCH_H */
