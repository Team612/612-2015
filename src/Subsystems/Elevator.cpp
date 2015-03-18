#include "Elevator.h"
#include <cmath>

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new CANTalon(ELEVATOR_MOTOR_1);
	//topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	//bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	elevEncoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	//leftIR = new AnalogInput(LEFT_IR);
	//rightIR = new AnalogInput(RIGHT_IR);
	//elevSensor = IR; //default to IR sensor
	middleUS = new AnalogInput(ELEVATOR_ULTRASONIC);
	middleIR = new AnalogInput(ELEVATOR_IR);
	leftIR = new AnalogInput(LEFT_FORK_IR);
	rightIR = new AnalogInput(RIGHT_FORK_IR);
	latchSol = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
}

Elevator::~Elevator()
{
	delete elevEncoder;
	delete middleUS;
	delete middleIR;
	delete leftIR;
	delete rightIR;
	delete latchSol;
	delete talon;
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float speed)
{
	talon->Set(speed);
	//printf("setting talon to 1 now\n");
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	move(0);
	//std::printf("Stop elevator motor\n");
}

Encoder* Elevator::getEncoder()
{
	return elevEncoder;//encoder;
}

bool Elevator::isLeftAligned()
{
	if(IRVoltageToDistance(leftIR->GetVoltage()) + TOTE_DETECT_TOLERANCE < (IRVoltageToDistance(middleIR->GetVoltage())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Elevator::isRightAligned()
{
	if(IRVoltageToDistance(rightIR->GetVoltage()) + TOTE_DETECT_TOLERANCE < (IRVoltageToDistance(middleIR->GetVoltage())))
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Elevator::getElevatorSensorHeight()//in inches
{

	if((USVoltageToDistance(middleUS->GetVoltage())+IRVoltageToDistance(middleIR->GetVoltage()))/2>SENSOR_THRESHOLD)
	{
		return USVoltageToDistance(middleUS->GetVoltage())-ELEVATOR_OFFSET;
	}
	else
	{
		return IRVoltageToDistance(middleIR->GetVoltage())-ELEVATOR_OFFSET;
	}
}

float Elevator::getElevatorEncoderHeight()//in inches
{
	return pow((ELEVATOR_SPOOL_DIAMETER * (elevEncoder->Get()/ENCODER_TICKS_PER_ROTATION)), (getElevatorSensorHeight())/100);
}

float Elevator::getElevatorHeight()//why does this method that does nothing exist? because of my OCD!
{
	return getElevatorEncoderHeight();//in inches, relative to the minimum height of the fork.
}

float Elevator::USVoltageToDistance(float voltage)
{
	//formula from here: http://www.maxbotix.com/articles/032.htm
	return (voltage/(5.0f/512.0f));//returns inches
}

float Elevator::IRVoltageToDistance(float voltage)
{
	return ((pow((27.0f/voltage),-1.1f))/2.54f); //returns inches (theoretically)
}

DoubleSolenoid* Elevator::getSolenoid()
{
	return latchSol;
}
