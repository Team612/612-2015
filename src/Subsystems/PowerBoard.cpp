#include "PowerBoard.h"
#include "../RobotMap.h"

PowerBoard::PowerBoard() :
		Subsystem("PowerDistributionPanel")
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
	powerboard->ResetTotalEnergy();
}

void PowerBoard::ClearStickyFaults()
{
	powerboard->ClearStickyFaults();
}

void PowerBoard::UpdateTable()
{
	powerboard->UpdateTable();
}

void PowerBoard::StartLiveWindowMode()
{
	powerboard->StartLiveWindowMode();
}

void PowerBoard::StopLiveWindowMode()
{
	powerboard->StopLiveWindowMode();
}

