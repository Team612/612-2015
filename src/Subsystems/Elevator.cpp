#include "Elevator.h"
#include <cmath>

Elevator::Elevator() :
	Subsystem("Elevator")
{
	elevTalon = new CANTalon(ELEVATOR_MOTOR_1);
	//topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	//bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	//elevEncoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	//leftIR = new AnalogInput(LEFT_IR);
	//rightIR = new AnalogInput(RIGHT_IR);
	//elevSensor = IR; //default to IR sensor
	middleUS = new AnalogInput(MIDDLE_FORK_US);
	middleIR = new AnalogInput(MIDDLE_FORK_IR);
	leftIR = new AnalogInput(LEFT_FORK_IR);
	rightIR = new AnalogInput(RIGHT_FORK_IR);
	latchSol = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
	prefs = Preferences::GetInstance();
}

Elevator::~Elevator()
{
	//delete elevEncoder;
	delete middleUS;
	delete middleIR;
	delete leftIR;
	delete rightIR;
	delete latchSol;
	delete elevTalon;
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float speed)
{
	elevTalon->Set(speed);
	//printf("setting talon to 1 now\n");
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	move(0);
	//std::printf("Stop elevator motor\n");
}

bool Elevator::isLeftAligned()
{
	printf("%f inches \n", IRVoltageToDistance(leftIR->GetVoltage()));
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
	printf("%f inches \n", IRVoltageToDistance(rightIR->GetVoltage()));
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
/*
	if((USVoltageToDistance(middleUS->GetVoltage())+IRVoltageToDistance(middleIR->GetVoltage()))/2>SENSOR_THRESHOLD)
	{
		return (USVoltageToDistance(middleUS->GetVoltage())-(prefs->GetInt("ELEV_OFFSET")));
	}
	else
	{
		return (IRVoltageToDistance(middleIR->GetVoltage())-(prefs->GetInt("ELEV_OFFSET")));
	}*/
	return (USVoltageToDistance(middleUS->GetVoltage())-(prefs->GetInt("ELEV_OFFSET")));
}

float Elevator::getElevatorEncoderHeight()//in inches
{
	return (ELEVATOR_SPOOL_DIAMETER * (elevTalon->GetEncPosition()/ENCODER_TICKS_PER_ROTATION));
}

float Elevator::getElevatorHeight()
{
	return pow(getElevatorEncoderHeight(),(getElevatorSensorHeight()/prefs->GetInt("ELEV_CALIBRATION"))+1);//in inches, relative to the minimum height of the fork.
}

float Elevator::USVoltageToDistance(float voltage)
{
	//formula from here: http://www.maxbotix.com/articles/032.htm
	return (voltage/0.009766f);//returns inches
}

float Elevator::IRVoltageToDistance(float voltage)
{
	//http://upgradeindustries.com/product/58/Sharp-10-80cm-Infrared-Distance-Sensor-(GP2Y0A21YK0F)
	return ((27.86f * pow(voltage, -1.15f)) * 0.393701f); //returns inches
}

DoubleSolenoid* Elevator::getSolenoid()
{
	return latchSol;
}

void Elevator::ResetSensors()
{
	elevTalon->SetControlMode(CANSpeedController::ControlMode::kPosition);
	elevTalon->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	elevTalon->Set(0.0f);
	elevTalon->SetPosition(0.0);
	elevTalon->SetNumberOfQuadIdxRises(0);
}
