#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <AnalogInput.h>
#include <CANTalon.h>
#include <include/IMU.h>
#include <cmath>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	//bool useIR = false;

	AnalogInput* ir;
	//Ultrasonic* ultra;
	//AnalogInput* infrared;

	//Encoder* encoderLR;
	//Encoder* encoderLF;
	//Encoder* encoderRR;
	//Encoder* encoderRF;

	bool useIR = false;
	//bool SwitchSensor(float distance); // Called in CheckSensor

public:
	Drivetrain(CANTalon* fl, CANTalon* fr, CANTalon* rf,CANTalon* rr, AnalogInput* infrared);
	void InitDefaultCommand();

	//void CheckSensor(float distance);
	void move(float x, float y, float rotation);
	void stop();
	int16_t getir();

	//Encoder Methods
	enum MotorLocation {FRONT_LEFT, FRONT_RIGHT, REAR_LEFT, REAR_RIGHT, FRONT_AVERAGE, LEFT_AVERAGE, REAR_AVERAGE, RIGHT_AVERAGE, MAJOR_DIAGONAL, MINOR_DIAGONAL, ALL_AVERAGE}; //For use in getDistance
	void resetEncoders(); //Resets ALL encoders
	float getDistance(MotorLocation location); //Gets the distance of a specific  motor

	CANTalon* fl;
	CANTalon* rl;
	CANTalon* fr;
	CANTalon* rr;

	float motor_power;

	IMU* imu;
};

#endif
