#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"


//GYRO
const uint32_t GYRO_CHANNEL = 0; // The channel for the gyro


//ENCODER
const uint32_t ENCODER_LR_A = 0; // The channels for the left rear encoder
const uint32_t ENCODER_LR_B = 0;

const uint32_t ENCODER_LF_A = 0; // The channels for the left front encoder
const uint32_t ENCODER_LF_B = 0;

const uint32_t ENCODER_RR_A = 0; // The channels for the right rear encoder
const uint32_t ENCODER_RR_B = 0;

const uint32_t ENCODER_RF_A = 0; // The channels for the right front encdoer
const uint32_t ENCODER_RF_B = 0;


//MOTORS
const uint32_t MOTOR_LR = 2; // The channel for the left rear motor
const uint32_t MOTOR_LF = 1; // The channel for the left front motor
const uint32_t MOTOR_RR = 3; // The channel for the right rear motor
const uint32_t MOTOR_RF = 4; // The channel for the right front motor

const float MOTOR_EXPIRATION = 0.5f; // float measured in milliseconds


//INFRARED TODO fix this number
const uint32_t INFRARED = 1; // The channel for infrared sensors


//ELEVATOR TODO fix these numbers
const uint32_t ELEVATOR_MOTOR = 1; // The channel for the elevator motors
const uint32_t ELEVATOR_TOP_SWITCH = 1; // The channel for the top switch of the elevator
const uint32_t ELEVATOR_BOTTOM_SWITCH = 1; // The channel for the bottom switch of the elevator
const uint32_t ELEVATOR_ENCODER_A = 1; // The channels for the elevator encoder
const uint32_t ELEVATOR_ENCODER_B = 1;

const uint32_t LEFT_IR = 1;
const uint32_t RIGHT_IR = 2;

const float CRATE_HEIGHT = 12.0f;
const float BUFFER = 2.0f;

const uint32_t ELEVATOR_ULTRASONIC = 1;
const uint32_t ELEVATOR_IR = 2;

const float MAX_IR = 60.0f; //TODO
const float MIN_ULTRA = 20.0f; //TODO



//JOYSTICK
static const float DEADZONE = 0.1f; // The value for the joystick deadzone
static const float THROTTLE = 1.0f;  // The value for the joystick throttle

static const uint32_t DRIVER_JOY = 0; // The channels for the driver joystick
static const uint32_t GUNNER_JOY = 1; // The channels for the gunner joystick

static const uint32_t LEFT_X = 0; // port for left joystick, x axis
static const uint32_t LEFT_Y = 1; // port for left joystick, y axis
static const uint32_t RIGHT_X = 4; // port for right joystick, x axis

static const uint32_t BUTTON_A = 1; // port for A button on xbox controller
static const uint32_t BUTTON_B = 2; // port for B button on xbox controller
static const uint32_t BUTTON_X = 3; // port for X button on xbox controller
static const uint32_t BUTTON_Y = 4; // port for Y button on xbox controller

#endif
