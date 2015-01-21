#ifndef Latch_H
#define Latch_H

#include "WPILib.h"

class Latch: public Subsystem
{
public:
	Latch();
	void Open();
	void Close();
};

#endif /* LATCH_H */
