/*
 * CANTalon612.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: zachary
 */

#include <CANTalon612.h>

/* This class makes a PIDController function as a SpeedController, which allows
 * for each motor to be driven independently by an internal PID controller.
 * The goal of this code is to prevent drift in the Mecanum wheel drive.
 *
 * The concept is as follows: Each motor has its own encoder.  Rather than
 * command the motors to spin based on a value, we command the motor speed
 * until the encoder rate (not the position) matches a desired rate.  Due to
 * mechanical variation (chain tension and alignment), each wheel has variation
 * in the necessary motor speed to achieve an encoder rate.
 *
 * Explanation of initialization: The constructor builds the talon, the
 * encoder, and then get the pointer to preferences.  The maximum encoder rate
 * is stored as a preference.  If the preferences exist, they are loaded for
 * the constants.  If they dont exist an estimated value for the maximum
 * encoder rate is used.  Finally, the initialization sets the input and output
 * and enables the PID controller.
 *
 * For use: Call Set() and it will check if the encoder value is bigger than
 * previous maximum encoder value seen. If the new value is larger, it will
 * make that the new max and save it. then it will tell PID to set the motor to
 * the PID'd value
 */


CANTalon612::CANTalon612(char* name, uint32_t talonID, uint32_t encoderDigitalInputA, uint32_t encoderDigitalInputB, float p, float i, float d, bool encoderInverted)
{
	motor_name = name;
	talon = new CANTalon(talonID);
	encoder = new Encoder(encoderDigitalInputA, encoderDigitalInputB, encoderInverted);
	prefs = Preferences::GetInstance();
	initPID(p, i, d);
}

CANTalon612::CANTalon612(char* name, uint32_t talonID, Encoder* e, float p, float i, float d)
{
	motor_name = name;
	talon = new CANTalon(talonID);
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID(p, i, d);
}

CANTalon612::CANTalon612(char* name, CANTalon* t, uint32_t encoderDigitalInputA, uint32_t encoderDigitalInputB, float p, float i, float d, bool encoderInverted)
{
	motor_name = name;
	talon = t;
	encoder = new Encoder(encoderDigitalInputA, encoderDigitalInputB, encoderInverted);
	prefs = Preferences::GetInstance();
	initPID(p, i, d);
}

CANTalon612::CANTalon612(char* name, CANTalon* t, Encoder* e, float p, float i, float d)
{
	motor_name = name;
	talon = t;
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID(p, i, d);
}

void CANTalon612::initPID(float p, float i, float d)
{
	P = p;
	I = i;
	D = d;

	readPrefs();
	pid = new PIDController(P, I, D, encoder, talon);
	//pid->SetInputRange(MIN_INPUT,MAX_INPUT); // not sure we want to do this.
	//TODO make this the actual input range
	//pid->SetOutputRange(getMaxOutput()*-1.0f, getMaxOutput());
	pid->Enable();
	// PID controllers also need to be enabled.
}

void CANTalon612::readPrefs()
{
	if (checkPrefs())
	{
		encoder_rate = prefs->GetFloat(motor_name);
	}
	else
	{
		std::printf("No Preferences found!\n");
		encoder_rate = DEFAULT_ENCODER_RATE;
		writePrefs(encoder_rate);
	}
}

bool CANTalon612::checkPrefs()
{
	if (prefs->ContainsKey(motor_name))
		return true;
	else
		return false;
}

int CANTalon612::writePrefs(float encoderRate)
{
	int exit_status = 0;
	if (checkPrefs())
		exit_status = 1;
	prefs->PutFloat(motor_name, encoderRate);
	prefs->Save();
	return exit_status;
}

CANTalon612::~CANTalon612()
{
	delete encoder;
	delete talon;
	delete pid;
}

void CANTalon612::Set(float value, uint8_t syncGroup)
{
	float rate = getEncoderValue();
	//make absolute value
	if (rate < 0)
		rate = rate*-1;
	//make the bigger max the new max
	if (rate > encoder_rate)
		writePrefs(encoder_rate);
	//set the motor
	pid->SetSetpoint(value*encoder_rate);
}

float CANTalon612::Get()
{
	return getEncoderValue();
}
void CANTalon612::Disable()
{
	Set(0.0f);
	talon->Set(0.0f);
	pid->Disable();
	// I'd set the motor to 0 --- not just Set()
	// maybe we should reset encoders here?
}

void CANTalon612::PIDWrite(float output)
{
	Set(output);  // I'm concerned that you don't implement a Set(float)
	// I think this doesn't call the function that you wrote.
}

float CANTalon612::getEncoderValue()
{
	//TODO make sure this works correctly
	// We do need to test this, but I like the programmed logic
	return (float)encoder->GetRate();
}
