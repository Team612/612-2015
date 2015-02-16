#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/*
 * SETTINGS
 */
const float MOTOR_EXPIRATION = 0.5f; // float measured in ms
/*
 * Drivetrain
 */
const uint32_t GYRO_CHANNEL = 0;

const uint32_t ENCODER_RL_A = 0;
const uint32_t ENCODER_RL_B = 0;

const uint32_t ENCODER_FL_A = 0;
const uint32_t ENCODER_FL_B = 0;

const uint32_t ENCODER_RR_A = 0;
const uint32_t ENCODER_RR_B = 0;

const uint32_t ENCODER_FR_A = 0;
const uint32_t ENCODER_FR_B = 0;

const uint32_t MOTOR_FR = 4;
const uint32_t MOTOR_FL = 1;
const uint32_t MOTOR_RR = 3;
const uint32_t MOTOR_RL = 2;

const uint32_t INFRARED = 1; //fix this number

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Placeholder values for elevator channels
/*
 * Elevator
 */
const uint32_t ELEVATOR_MOTOR = 1;
const uint32_t ELEVATOR_TOP_SWITCH = 1;
const uint32_t ELEVATOR_BOTTOM_SWITCH = 1;
const uint32_t ELEVATOR_ENCODER_A = 1;
const uint32_t ELEVATOR_ENCODER_B = 1;
//LATCH
const uint32_t SOLENOID_LATCH = 1;
const uint32_t RELAY_LATCH = 1;

//Pneumatics
const uint32_t PCM = 11;



/*
 * JOYSTICK STUFF
 */
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
static const uint32_t RIGHT_Y = 5;
//Buttons
static const uint32_t BUTTON_A = 1;
static const uint32_t BUTTON_B = 2;
static const uint32_t BUTTON_X = 3;
static const uint32_t BUTTON_Y = 4;

#endif
