#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "GamePad.h"

//Setings
//#define IMU
#define GAMEPAD

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
const uint32_t MOTOR_FR = 2; // The channel for the rear left motor
const uint32_t MOTOR_FL = 1; // The channel for the front left motor
const uint32_t MOTOR_RR = 3; // The channel for the rear right motor
const uint32_t MOTOR_RL = 4; // The channel for the front right motor
//const uint32_t MOTOR_LEFT_FEED = 5; // The channel for the front right motor
//const uint32_t MOTOR_RIGHT_FEED = 6; // The channel for the front right motor

const float MOTOR_EXPIRATION = 1000.0f; // float measured in milliseconds
const float MOTOR_LOW = 0.4f;
const float MOTOR_HIGH = 1.0f;

//INFRARED TODO fix this number
const uint32_t INFRARED = 1; // The channel for infrared sensors

//ELEVATOR TODO fix these numbers
const uint32_t ELEVATOR_MOTOR_1 = 6; // The channel for the elevator motors
const uint32_t ELEVATOR_MOTOR_2 = -1;
const uint32_t ELEVATOR_TOP_SWITCH = 1; // The channel for the top switch of the elevator
const uint32_t ELEVATOR_BOTTOM_SWITCH = 1; // The channel for the bottom switch of the elevator
const uint32_t ELEVATOR_ENCODER_A = 1; // The channels for the elevator encoder
const uint32_t ELEVATOR_ENCODER_B = 2;
const uint32_t LEFT_FORK_IR = 1;//TODO actually fill in this port
const uint32_t RIGHT_FORK_IR = 2;//TODO actually fill in this port
const uint32_t MIDDLE_FORK_US = 0;
const uint32_t MIDDLE_FORK_IR = 2;
const uint32_t LEFT_FEED_MOTOR = 5;
const uint32_t RIGHT_FEED_MOTOR = 7;

const float TOTE_DETECT_TOLERANCE = 6.0f;//in inches
const float ELEVATOR_SPOOL_DIAMETER = 10.12f;//inches
const float ELEVATOR_TOLERANCE = 1.5f;// in inches
const float SENSOR_THRESHOLD = 18.24805f;//average of lower sensor limit of US and upper accuracy limit of IR.

const int ENCODER_TICKS_PER_ROTATION = 1023;//might be 1440
//const float ELEV_SPEED_FLOAT = 0.8f;
//const double ELEV_SPEED_DOUBLE = 0.8;

//const int ELEVATOR_TOLERANCE = 50;

//IMU
const uint32_t SERIAL_PORT = 0;
const uint8_t REFRESH_RATE = 50;

//JOYSTICK
static const float DEADZONE = 0.1f; // The value for the joystick deadzone
static const float THROTTLE = 1.0f;  // The value for the joystick throttle

static const uint32_t DRIVER_JOY = 0; // The channels for the driver joystick
static const uint32_t GUNNER_JOY = 1; // The channels for the gunner joystick
#ifdef GAMEPAD
static const uint32_t LEFT_X  = 1; // port for left joystick, x axis
static const uint32_t LEFT_Y  = 0; // port for left joystick, y axis
static const uint32_t RIGHT_X = 4; // port for right joystick, x axis
static const uint32_t RIGHT_Y = 5;

#else

static const uint32_t LEFT_X  = 0; // port for left joystick, x axis
static const uint32_t LEFT_Y  = 1; // port for left joystick, y axis
static const uint32_t RIGHT_X = 2; // port for right joystick, x axis

static const uint32_t SLIDER = 3;
#endif

//TESTING
static const uint32_t BUTTON_A = 1; // port for A button on xbox controller
static const uint32_t BUTTON_B = 2; // port for B button on xbox controller
static const uint32_t BUTTON_X = 3; // port for X button on xbox controller
static const uint32_t BUTTON_Y = 4; // port for Y button on xbox controller
static const uint32_t BUTTON_LB = 5;
static const uint32_t BUTTON_RB = 6; // port for Y button on xbox controller


const uint32_t SOLENOIDCHAN1 = 0; // check correct values
const uint32_t SOLENOIDCHAN2 = 1;
const uint32_t TIMER_VALUE = 1.1;

const uint32_t PCM = 0;

#endif
