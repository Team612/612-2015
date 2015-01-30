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

const uint32_t MOTOR_LR = 1;
const uint32_t MOTOR_LF = 2;
const uint32_t MOTOR_RR = 3;
const uint32_t MOTOR_RF = 4;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
static const uint32_t TALON1_CHANNEL = 1;
static const uint32_t TALON2_CHANNEL = 2;
static const uint32_t TALON3_CHANNEL = 3;
static const uint32_t TALON4_CHANNEL = 4;

//Mapping the joystick stuff
static const uint32_t XBOX_CONTROLLER = 3;
static const uint32_t LEFT_JOYSTICK = 0;
static const uint32_t RIGHT_JOYSTICK = 1;

static const uint32_t BUTTON_A = 1;
static const uint32_t BUTTON_B = 2;
static const uint32_t BUTTON_X = 3;
static const uint32_t BUTTON_Y = 4;

#endif
