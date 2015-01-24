#include "PowerBoard.h"
#include "../RobotMap.h"

PowerBoard::PowerDistributionPanel() :
		Subsystem("PowerDistributionPanel");
{
	powerboard = new PowerDistributionPanel();
}

void PowerBoard::InitDefaultCommand()
{
	//Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call from Commands
	

void PowerBoard::InitDefaultCommand()
{
	//Fill this later
}
double PowerBoard::GetVoltage()
{
	return powerboard->GetVoltage();
}
	
double PowerBoard::GetTemperature()
{
	return powerboard->GetTemperature();
}

double PowerBoard::GetCurrent(uint8_t channel)
{
	return powerboard->GetCurrent(channel);
}

double PowerBoard::GetTotalCurrent()
{
	return powerboard->GetTotalCurrent();
}

double PowerBoard::GetTotalPower()
{
	return powerboard->GetTotalPower();
}

double PowerBoard::GetTotalEnergy()
{
	return powerboard->GetTotalEnergy();
}

void PowerBoard::ResetTotalEnergy()
{	
	return powerboard->ResetTotalEnergy();
}

void PowerBoard::ClearStickyDefaults()
{
	return powerboard->ClearStickyDefaults();
}

void PowerBoard::UpdateTable()
{
	return powerboard->UpdateTable();
}

void PowerBoard::StartLiveWindowMode()
{
	return powerboard->StartLiveWindowMode();
}

void PowerBoard::StopLiveWindowMode()
{
	return powerboard->StopLiveWindowMode();
}

