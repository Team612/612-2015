#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Settings
const float THROTTLE = 0.3f;
const float TOLORANCE = 0.1f;
#define DEBUG

	//RoboRIO ports
//DriveTrain
const uint32_t TALON_FL = 1;
const uint32_t TALON_FR = 0;
const uint32_t TALON_BL = 2;
const uint32_t TALON_BR = 3;

//Gamepad
const int LEFT_X = 0;
const int LEFT_Y = 1; //Reverse this axis
const int RIGHT_X = 4; //Reverse this axis

#endif
