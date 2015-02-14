#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetBoundingBox: public CommandBase
{
public:
	GetBoundingBox();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
