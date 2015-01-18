#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"
#include "../Subsystems/MecanumDrivetrain.h"

class Drive: public CommandBase
{
	private:
	float magnitude;
	float direction;
	float rotation;
public:
	Drive(float inMagnitude, float inDirection, float inRotation);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
