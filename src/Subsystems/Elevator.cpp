#include "Elevator.h"
#include <cmath>

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new CANTalon(ELEVATOR_MOTOR_1);
#ifdef TALON
	talon2 = new CANTalon(ELEVATOR_MOTOR_2);
#endif
	//topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	//bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	elevEncoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	//leftIR = new AnalogInput(LEFT_IR);
	//rightIR = new AnalogInput(RIGHT_IR);
	//elevSensor = IR; //default to IR sensor
	elevUS = new AnalogInput(ELEVATOR_ULTRASONIC);
	elevIR = new AnalogInput(ELEVATOR_IR);
	latchSol = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
}

Elevator::~Elevator()
{
	delete talon;
#ifdef TALON
	delete talon2;
#endif
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float speed)
{
	/*
	//Checks the sensors to see if the elevator is at the top or the bottom
	bool topInput = topSwitch->Get();
	bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the elevator can't be moved more that way, so don't move
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
	static int count = 0;
	if (count % 60 == 0)
	{
		printf("Elevator motor moved! Speed = %f", magnitude);
	}
	*/
	talon->Set(speed);
	printf("setting talon to 1 now\n");
#ifdef TALON
	talon2->Set(magnitude);
#endif
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
#ifdef TALON
	talon2->Set(0);
#endif
	std::printf("Stop elevator motor\n");
}

Encoder* Elevator::getEncoder()
{
	return elevEncoder;//encoder;
}

bool Elevator::getLeftAlignment()
{
	/*
	float val = leftIR->GetVoltage();
	val = IRVoltageToDistance(val);
	float dist = 0.0f;
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		return false;
	}

	return true;
	*/
	return false;
}

bool Elevator::getRightAlignment()
{
	/*
	float val = rightIR->GetVoltage();
	val = IRVoltageToDistance(val);
	float dist = 0.0f; //FIX THIS PLACEHOLDER VALUE TODO
	
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		printf("Crate not found");
		return false;
	}
	*/
	return false;//true;
}

float Elevator::IRVoltageToDistance(float val)
{
	return (pow((4187.8/val),1.1060))/2.54; //make sure this is right, make sure it returns INCHES
}

float Elevator::getElevatorHeight()
{/*
	if (elevSensor == IR)
	{
		float voltage = 1.0f;//elevatorIR->GetVoltage();
		return IRVoltageToDistance(voltage);
	}
	else
	{
		float voltage = elevUS->GetVoltage();
		return UltrasonicVoltageToDistance(voltage);
	}*/
	if((UltrasonicVoltageToDistance(elevUS->GetVoltage())+IRVoltageToDistance(elevIR->GetVoltage()))/2>ELEVTHRESHOLD)
	{
		return UltrasonicVoltageToDistance(elevUS->GetVoltage());
	}
	else
	{
		return IRVoltageToDistance(elevIR->GetVoltage());
	}
}

float Elevator::UltrasonicVoltageToDistance(float voltage)
{
	//int16_t inputVoltage = ultrasonic->GetValue(); //Zach said this should always be 5, so I'll try that
	float voltsPerInch = 5.0/512.0; //Very small number
	voltsPerInch *= 1000; //converts to mV
	//formula from here: http://www.maxbotix.com/articles/032.htm confused by it
	return voltage/voltsPerInch; //TODO test to make sure this works
	
}

/*Elevator::MainSensor Elevator::switchSensor(float IRDistance, float UDistance)
{
	if(IRDistance > MAX_IR)
	{
		return ULTRASONIC;
	}
	else if(UDistance < MIN_US)
	{
		return IR;
	}
	else //Buffer zone
	{
		return elevSensor;
	}
}*/

DoubleSolenoid* Elevator::getSolenoid()
{
	return latchSol;
}

