#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"
#include "../Subsystems/MecanumDrivetrain.h"

class Drive: public CommandBase
{
private:

public:
	Drive();
	void Initialize();
	void Execute(float inMagnitude, float inDirection, float inRotation);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
