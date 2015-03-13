#ifndef AngleAlgor_H
#define AngleAlgor_H

#include "../CommandBase.h"
#include "WPILib.h"

class AngleAlgor: public CommandBase
{
private:
	//all ratios are width/height
	//TODO fill in values
	const float toteLength = 0;
	const float toteWidth = 0;
	const float toteHeight = 0;
	const float toteDiagonal = 0;
	const float shortFaceRatio = toteWidth/toteHeight;
	const float longFaceRatio = toteLength/toteHeight;
	const float maxFaceRatio = toteDiagonal/toteHeight;
	const float maxRatioAngle = 0;
public:
	AngleAlgor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
