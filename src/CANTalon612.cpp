/*
 * CANTalon612.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: zachary
 */

#include <CANTalon612.h>

/*
 * Explanation of initialization:
 * The object will build the talon, the encoder then get the pointer to preferences
 * Then the object will check the preferences and if they exist, load them
 * if they dont exist and no PID values were passed to it, it will default to P=1 I=D=0
 * if you passed in PID values, then it will make those the values for THIS RUN ONLY unless
 * you passed in the override or there are no existing values
 *
 * Then it just sets the input and output and enables the PID controller
 *
 * For use: Call set and it will check if the output is bigger than previous output. If it is
 * then it will make that the new max and save it. then it will tell PID to set the motor to the PID'd value
 */

CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, bool inverted)
{
	talon = new CANTalon(port);
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = Preferences::GetInstance();
	initPID();
}

CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted, bool override)
{
	talon = new CANTalon(port);
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}

CANTalon612::CANTalon612(uint32_t port, Encoder* e)
{
	talon = new CANTalon(port);
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID();
}

CANTalon612::CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override)
{
	talon = new CANTalon(port);
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}

void CANTalon612::initPID()
{
	readPrefs();
	pid = new PIDController(P, I, D, encoder, talon);
	pid->SetInputRange(MIN_INPUT,MAX_INPUT); // not sure we want to do this.
	//TODO make this the actual input range
	pid->SetOutputRange(getMaxOutput()*-1.0f, getMaxOutput());
	pid->Enable();
	// PID controllers also need to be enabled.
}

void CANTalon612::initPID(float p, float i, float d, bool override)
{
	if (override || checkPrefs() == false)
	{
		writePrefs(p,i,d);
	}
	else
	{
		P = p;
		I = i;
		D = d;
	}
	pid = new PIDController(P, I, D, encoder, talon);
	pid->SetInputRange(MIN_INPUT,MAX_INPUT); // not sure we want to do this.
	//TODO make this the actual input range
	pid->SetOutputRange(getMaxOutput()*1.0f, getMaxOutput());
	pid->Enable();
}

void CANTalon612::readPrefs()
{
	if (checkPrefs())
	{
		P = prefs->GetFloat("P");
		I = prefs->GetFloat("I");
		D = prefs->GetFloat("D");
	}
	else
	{
		std::printf("No Preferences found!\n");
		P = 1.0f; // don't default to all 3 being zero.
		I = 0.0f;
		D = 0.0f;
	}
}

bool CANTalon612::checkPrefs()
{
	if (prefs->ContainsKey("P") && prefs->ContainsKey("I") && prefs->ContainsKey("D"))
		return true;
	else
		return false;
}

int CANTalon612::writePrefs(float p, float i, float d)
{
	int exit_status = 0;
	if (checkPrefs())
		exit_status = 1;
	prefs->PutFloat("P", p);
	prefs->PutFloat("I", i);
	prefs->PutFloat("D", d);
	prefs->Save();
	return exit_status;
}

CANTalon612::~CANTalon612()
{
	delete encoder;
	//CANTalon::~CANTalon();
}

void CANTalon612::Set(float value, uint8_t syncGroup)
{
	float out = getOutput();
	//make absolute value
	if (out < 0)
		out = out*-1;
	//make the bigger max the new max
	if (out > maxOut)
		setMaxOutput(out);
	//set the motor
	pid->SetSetpoint(value*maxOut);
}

float CANTalon612::Get()
{
	return getOutput();
}
void CANTalon612::Disable()
{
	Set(0.0f);
}

void CANTalon612::PIDWrite(float output)
{
	Set(output);
}

float CANTalon612::getOutput()
{
	//TODO make sure this works correctly
	return (float)encoder->GetRate();
}

void CANTalon612::setMaxOutput(float out)
{
	maxOut = out;
	prefs->PutFloat("Max", out);
	prefs->Save();
}
//use this for the first time to load from the file
float CANTalon612::getMaxOutput()
{
	if (prefs->ContainsKey("Max"))
	{
		maxOut = prefs->GetFloat("Max");
		return maxOut;
	}
	else
	{
		maxOut = DEFAULT_MAX_OUT;
		return maxOut;
	}
}

