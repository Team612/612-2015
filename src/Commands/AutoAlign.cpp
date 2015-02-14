#include "AutoAlign.h"

AutoAlign::AutoAlign() {

}

void AutoAlign::RoughAlign(float distanceToTote, float bearingToTote, float distanceToBeAway) //good for autonomous. It aligns itself to the front of the tote. some what accurate.
{
	Requires(drivetrain);
	//Look at issue #126 to understand
	drivetrain->move(0.0f, 0.0f, bearingToTote*-1); //turn left parallel to tote
	drivetrain->move(cos(bearingToTote * (3.14159 / 180.0))*distanceToTote, 0.0f, 0.0f); //move sideways to in front of tote
	drivetrain->move(0.0f, (sin(bearingToTote * (3.14159 / 180.0))*distanceToTote) - distanceToBeAway, 0.0f); //move to the tote (the distanceToBeAway variable is the distance it will be away from the tote)
}

float AutoAlign::CalculateBearing(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle) //Look at diagram #4 at https://github.com/Chantilly612Code/612-2015/issues/126 to understand
{
	float H = 0.0; //The difference of the height of lines perpendicular to the robot of the two points
	float L = 0.0; //The total width of the widths of the right triangles created from the two points
	H = (sin(firstPointAngle * (3.14159 / 180.0)) * firstPointDistance) - (sin(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance); //Calculates the difference of the height of lines perpendicular to the robot of the two points
	L = (cos(firstPointAngle * (3.14159 / 180.0)) * firstPointDistance) + (cos(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance); //Calculates the total width of the widths of the right triangles created from the two points
	return 90.0 - atan(H/L); //I also want a tan. Returns the relative angle needed for bearingToTote in RoughAlign()
}
