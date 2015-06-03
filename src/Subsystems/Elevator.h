
#ifndef LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_
#define LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_

#include "WPILib.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>
#include <TalonSRX.h>

class Elevator : public Subsystem {
private:
	CANTalon* talon; ///< First talon object
#ifdef TALON
	CANTalon* talon2; ///< If the robot got it, second talon object
#endif
	//DigitalInput* topSwitch;
	//DigitalInput* bottomSwitch;
	Encoder* encoder; ///< Encoder object (on talon to measure distance)
	//AnalogInput* leftIR;
	//AnalogInput* rightIR;
	/// Converts voltage to distance
	/// Used to convert voltage from the IR sensor to distance
	/// Never 100% sure this function ever worked
	///@param val voltage from the IR sensor
	float voltageToDistance(float val);
	/// Which sensor to be used by the robot
	/// Ultrasonic and Infrared have different distances that they are accurate for
	typedef enum _MainSensor
	{
		ULTRASONIC, ///< Ultrasonic being used to detect distance
		IR ///< infrared being used to dectect
	} MainSensor;
	MainSensor sense; ///<Variable used to store which sensor being used
	const float SWITCH_TO_ULTRASONIC = 12.0f; ///< Temp value for when to switch from IR to US
	const float SWITCH_TO_IR = 6.0f; ///< Temp value to switch from US to IR
	AnalogInput* ultrasonic; ///< Ultrasonic object
	AnalogInput* elevatorIR; ///< Infrared Object (used on elevator)
	///Switches sensor if necessary
	///If value of one falls outside of accurate range of other, switch
	///Default set to IR
	///@param IRDistance distance detected by IR
	///@param UDistance distance detected by ultrasonic
	MainSensor switchSensor(float IRDistance, float UDistance);
	DoubleSolenoid* latchSol; ///<Double solenoid object (for latch)
public:
	Elevator(); ///<Elevator constructor
	virtual ~Elevator(); ///< Elevator deconstructor
	///Moves elevator
	///Moves elevator at a given speed
	///@param speed float that says what speed to move elevator at
	void move(float speed);
	void stop(); ///< Stops elevator (incase of tipping)
	void InitDefaultCommand(); ///< Starts default command
	Encoder* getEncoder(); ///< Function that returns the encoder
	bool getLeftAlignment(); ///< Returns if left side of robot is aligned with crate
	bool getRightAlignment(); ///< Returns if right side of robot is aligned with crate
	float getElevatorHeight(); ///< Gets height of elevator from ground
	float UltrasonicVoltageToDistance(float val); ///<Converts voltage to distance (US)
	float IRVoltageToDistance(float val); ///< Converts voltage to distance (IR)
	DoubleSolenoid* getSolenoid(); ///< Returns solenoid
};

#endif /* LATCH_CPP_SRC_SUBSYSTEMS_ELEVATOR_H_ */