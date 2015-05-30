#ifndef MecanumDrivetrain_H
#define MecanumDrivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <MotorSafetyHelper.h>
#include <AnalogInput.h>
#include <CANTalon.h>
#include <include/IMU.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	//bool useIR = false;

	AnalogInput* ir; ///< Infrared object
	//Ultrasonic* ultra;
	//AnalogInput* infrared;

	//Encoder* encoderLR;
	//Encoder* encoderLF;
	//Encoder* encoderRR;
	//Encoder* encoderRF;

	bool useIR = false; ///<Bool if using IR to detect distance
	//bool SwitchSensor(float distance); // Called in CheckSensor

public:
	///Constructor for drivetrain
	///@param fl front left talon
	///@param fr front right talon
	///@param rf rear front talon
	///@param rr rear right talon
	///@param infrared Object used to detect distance
	Drivetrain(CANTalon* fl, CANTalon* fr, CANTalon* rf,CANTalon* rr, AnalogInput* infrared);
	void InitDefaultCommand(); ///< Inits default command for drivetrain

	//void CheckSensor(float distance);
	///Moves drivetrain
	///@param x distance to move left/right (inches? Encoder measurement?)
	///@param y distance to move forward/back (inches? Encoder?)
	///@param rotation degrees to rotate (NOT RADIANS)
	void move(float x, float y, float rotation);
	void stop();///< Stops robot
	int16_t getir(); ///<Returns IR sensor object

	//Encoder Methods
	enum MotorLocation {LEFT_FRONT, LEFT_REAR, RIGHT_FRONT, RIGHT_REAR}; ///<For use in getDistance
	//void resetEncoders(); //Resets ALL encoders
	int32_t getDistance(MotorLocation location); ///<Gets the distance of a specific motor
	//void SetRightFeedWheel(float speed);
	//void SetLeftFeedWheel(float speed);

	CANTalon* fl; ///< front left talon object
	CANTalon* rl; ///< rear left talon object
	CANTalon* fr; ///< front right talon object
	CANTalon* rr; ///< rear right talon object

	float motor_power; ///< power of motor (0-1)

	IMU* imu; ///<Object to detect intertia (I think?)
};

#endif
