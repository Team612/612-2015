#ifndef AUTO_ALIGN_GROUP_H
#define AUTO_ALIGN_GROUP_H

#include "Commands/CommandGroup.h"
#include "../Subsystems/Drivetrain.h"
#include "Drive.h"

class AutoAlign: public CommandBase
{
public:
	AutoAlign();
	void RoughAlign(float distanceToTote, float bearingToTote, float distanceToBeAway); //bearing is in degrees. look at issue #126
	float CalculateBearing(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle); //first point is the further edge, second point is the closest edge
};

#endif

/*           DIAGRAM:
 * ------------------------------
 *
 * first point ->  +------+
 *                 |      |
 *                 | Tote |
 *                 |      |
 * 				   |      |
 * second point -> +------+
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
