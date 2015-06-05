#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Vision(); ///< Constructor for vision
	void InitDefaultCommand(); ///< Initialized default vision command (never used)
};

#endif
