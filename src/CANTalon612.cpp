/*
 * CANTalon612.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: zachary
 */

#include <CANTalon612.h>

CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, bool inverted) : CANTalon(port)
{
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = Preferences::GetInstance();
	initPID();
}

CANTalon612::CANTalon612(uint32_t port, uint32_t encoderA, uint32_t encoderB, float p, float i, float d, bool inverted, bool override) : CANTalon(port)
{
	encoder = new Encoder(encoderA, encoderB, inverted);
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}

CANTalon612::CANTalon612(uint32_t port, Encoder* e) : CANTalon(port)
{
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID();
}

CANTalon612::CANTalon612(uint32_t port, Encoder* e, float p, float i, float d, bool override) : CANTalon(port)
{
	encoder = e;
	prefs = Preferences::GetInstance();
	initPID(p, i, d, override);
}

void CANTalon612::initPID()
{
	readPrefs();
	pid = new PIDController(P, I, D, encoder, this);
	// I don't think we should extend a CANTalon.  Using this keyword here is
	// not going to do the desired effect.  Your PID controller is going to
	// use PIDWrite(), which calls Set() which changes the PIDController's
	// SetSetPoint().  This in no way changes the motor output speed.
	// Thus, you need a CANTalon object, separate from the this keyword object.
	pid->SetInputRange(-1.0,1.0); // not sure we want to do this.
	pid->SetOutputRange(getMaxOutput()*-1.0f, getMaxOutput());
	// PID controllers also need to be enabled.  Look at WPILIB docs.
}

void CANTalon612::initPID(float p, float i, float d, bool override)
{
	if (override || checkPrefs() == false)
	{
		writePrefs(p,i,d);
	}
	else
	{
		readPrefs();
	}
	pid = new PIDController(P, I, D, encoder, this);
	pid->SetInputRange(-1.0,1.0); // not sure we want to do this.
	pid->SetOutputRange(getMaxOutput()*1.0f, getMaxOutput());
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

void CANTalon612::PIDWrite(float output)
{
	Set(output);
}

void CANTalon612::Set(float value)
{
	float out = getOutput();
	// todo: missing absolute value.
	if (out > maxOut)
	{
		setMaxOutput(out);
	}
	pid->SetSetpoint(value*maxOut);
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
		maxOut = 1.0f;
		return maxOut;
	}
}
