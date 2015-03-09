#ifndef AUTO_ALIGN_GROUP_H
#define AUTO_ALIGN_GROUP_H

#include "Commands/CommandGroup.h"
#include "../Subsystems/Drivetrain.h"
#include "Drive.h"

class AutoAlign: public CommandBase
{
private:
	const float maxAlignDistance = 50.0; //the max distance that the robot should be at least at to autoalign.
	const float distanceToAutoAlign = 10.0; //should be smaller than maxAlignDistance. The optimal distance (robot to tote) to autoalign.
public:
	AutoAlign();
	float CalculateBearing(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle); //first point is the further edge, second point is the closest edge
	void AutonoumousAutoAlign(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle);
};

#endif

/*           DIAGRAM:
 * ------------------------------
 *
 * first point ->  +------+ (if the first point is on the long side, then the robot will align to the short side and vice versa)
 *                 |      |
 *                 | Tote |
 *                 |      |
 * 				   |      |
 * second point -> +------+ (second point is the closest to the robot's sensor)
 *
 *
 *  |  /
 *  | /
 *  o <- sweeping sensor
 *
 *  -----------------------------
 *
 *  Look at diagrams at https://github.com/Chantilly612Code/612-2015/issues/126
 */
