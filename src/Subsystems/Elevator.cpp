#include "Elevator.h"
#include <cmath>

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new CANTalon(ELEVATOR_MOTOR_1);
	talon2 = new CANTalon(ELEVATOR_MOTOR_2);
	topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	leftIR = new AnalogInput(LEFT_IR);
	rightIR = new AnalogInput(RIGHT_IR);
	sense = IR; //default to IR sensor
	ultrasonic = new AnalogInput(ELEVATOR_ULTRASONIC);
	elevatorIR = new AnalogInput(ELEVATOR_IR);
	latchSol = new DoubleSolenoid(LATCH_SOLENOID1, LATCH_SOLENOID2);
}

Elevator::~Elevator()
{
	delete talon;
	delete talon2;
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
		talon2->Set(0);
	}
	else
	{

		talon->Set(magnitude);
		talon2->Set(magnitude);
	}
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
	talon2->Set(0);
}

Encoder* Elevator::getEncoder()
{
	return encoder;
}

bool Elevator::getLeftAlignment()
{
	float val = leftIR->GetVoltage();
	val = IRVoltageToDistance(val);
	float dist = 0.0f;
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		return false;
	}

	return true;
}

bool Elevator::getRightAlignment()
{
	float val = rightIR->GetVoltage();
	val = IRVoltageToDistance(val);
	float dist = 0.0f; //FIX THIS PLACEHOLDER VALUE TODO
	
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		printf("Crate not found");
		return false;
	}
	return true;
}

float Elevator::IRVoltageToDistance(float val)
{
	return (pow((4187.8/val),1.1060))/2.54; //make sure this is right, make sure it returns INCHES
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

Elevator::MainSensor Elevator::switchSensor(float IRDistance, float UDistance)
{
	if(IRDistance > MAX_IR)
	{
		return ULTRASONIC;
	}
	else if(UDistance < MIN_ULTRA)
	{
		return IR;
	}
	else //Buffer zone
	{
		return sense;
	}
}

void Elevator::latchSolOpen()
{
	latchSol->Set(DoubleSolenoid::Value::kForward);
	printf("Setting DoubleSolenoid 1 on!\n");
}

void Elevator::latchSolClose()
{
	latchSol->Set(DoubleSolenoid::Value::kOff);
	printf("Setting DoubleSolenoid 1 off!\n");
}
