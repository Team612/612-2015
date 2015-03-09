#include "AutoAlign.h"

AutoAlign::AutoAlign() {

}


float AutoAlign::CalculateBearing(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle) //Look at diagram #4 at https://github.com/Chantilly612Code/612-2015/issues/126 to understand
{
	float H = 0.0; //The difference of the height of lines perpendicular to the robot of the two points
	float L = 0.0; //The total width of the widths of the right triangles created from the two points
	H = (sin(firstPointAngle * (3.14159 / 180.0)) * firstPointDistance) - (sin(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance); //Calculates the difference of the height of lines perpendicular to the robot of the two points
	L = (cos(firstPointAngle * (3.14159 / 180.0)) * firstPointDistance) + (cos(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance); //Calculates the total width of the widths of the right triangles created from the two points
	return 90.0 - atan(H/L); //I also want a tan. Returns the relative angle needed for bearingToTote in RoughAlign()
}

void AutoAlign::AutonoumousAutoAlign(float firstPointDistance, float firstPointAngle, float secondPointDistance, float secondPointAngle) //useful for autonomous
{
	if(sin(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance > maxAlignDistance)
	{
		drivetrain->move(cos(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance, 0.0f, 0.0f);
		drivetrain->move(0.0f, maxAlignDistance - distanceToAutoAlign, 0.0f);
	}
	RoughAlign(sin(secondPointAngle * (3.14159 / 180.0)) * secondPointDistance, CalculateBearing(firstPointDistance, firstPointAngle, secondPointDistance, secondPointAngle), 5.0f);
}
