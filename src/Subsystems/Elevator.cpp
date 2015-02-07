#include "Elevator.h"

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new Talon(ELEVATOR_MOTOR);
	topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	leftIR = new AnalogInput(LEFT_IR);
	rightIR = new AnalogInput(RIGHT_IR);
	sense = IR; //default to IR sensor
	ultrasonic = new AnalogInput(ELEVATOR_ULTRASONIC);
	elevatorIR = new AnalogInput(ELEVATOR_IR);
}

Elevator::~Elevator()
{
	delete talon;
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float magnitude)
{
	//Checks the sensors to see if the elevator is at the top or the bottom
	bool topInput = topSwitch->Get();
	bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the motors are set to a speed of 0
	if (topInput || bottomInput)
	{
		talon->Set(0);
	}
	else
	{
		talon->Set(magnitude);
	}
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
}

Encoder* Elevator::getEncoder()
{
	return encoder;
}

bool Elevator::getLeftAlignment()
{
	val = leftIR->GetVoltage();
	val = IRVoltageToDistance(val);
	
	if (val >= (distance - BUFFER) && val <= (distance + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		return false;
	}
	else
	{
		return true;
	}
	
}
bool Elevator::getRightAlignment()
{
	val = rightIR->GetVoltage();
	val = IRVoltageToDistance(val);
	
	if (val >= (distance - BUFFER) && val <= (distance + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		printf("Crate not found");
		return false;
	}
	else
	{
		return true;
	}
	
}

float Elevator::IRVoltageToDistance(float val)
{
	return ((4187.8/val)**1.1060)/2.54; //make sure this is right, make sure it returns INCHES
}

float Elevator::getElevatorHeight()
{
	if (sense == IR)
	{
		float voltage = elevatorIR->GetVoltage();
		return IRVoltageToDistance(voltage);
	}
	else
	{
		float voltage = ultrasonic->GetVoltage();
		return UltrasonicVoltageToDistance(voltage);
	}
}

float Elevator::UltrasonicVoltageToDistance(float voltage)
{
	float VoltageInch = voltage/512.0;
	VoltageInch *= 1000.0;
	//formula from here: http://www.maxbotix.com/articles/032.htm confused by it
	return 1.0f; //fix
	
}

MainSensor Elevator::switchSensor()
{
	if(IR > MAX_IR)
	{
		return ULTRASONIC;
	}
	else if(U < MIN_ULTRA)
	{
		return IR;
	}
}