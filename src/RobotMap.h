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

const uint32_t GYRO_CHANNEL = 0;

const uint32_t ENCODER_LR_A = 0;
const uint32_t ENCODER_LR_B = 0;

const uint32_t ENCODER_LF_A = 0;
const uint32_t ENCODER_LF_B = 0;

const uint32_t ENCODER_RR_A = 0;
const uint32_t ENCODER_RR_B = 0;

const uint32_t ENCODER_RF_A = 0;
const uint32_t ENCODER_RF_B = 0;

const uint32_t MOTOR_LR = 1;
const uint32_t MOTOR_LF = 2;
const uint32_t MOTOR_RR = 3;
const uint32_t MOTOR_RF = 4;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Placeholder values for elevator channels
const uint32_t ELEVATOR_MOTOR = 1;
const uint32_t ELEVATOR_TOP_SWITCH = 1;
const uint32_t ELEVATOR_BOTTOM_SWITCH = 1;
const uint32_t ELEVATOR_ENCODER_A = 1;
const uint32_t ELEVATOR_ENCODER_B = 1;

const uint32_t SOLENOID_LATCH = 1;

const uint32_t RELAY_LATCH = 1;

const float MOTOR_EXPIRATION = 0.1f; // float measured in seconds

//Mapping the joystick stuff
//Settings
static const float DEADZONE = 0.1f;
static const float THROTTLE = 1.0f;
//Joystick ports
static const uint32_t DRIVER_JOY = 0;
static const uint32_t GUNNER_JOY = 1;
//Axis
static const uint32_t LEFT_X = 0;
static const uint32_t LEFT_Y = 1;
static const uint32_t RIGHT_X = 4;
//Buttons
static const uint32_t BUTTON_A = 1;
static const uint32_t BUTTON_B = 2;
static const uint32_t BUTTON_X = 3;
static const uint32_t BUTTON_Y = 4;

#endif
