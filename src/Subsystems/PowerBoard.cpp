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
// here. Call these from Commands.
	

void PowerBoard::InitDefaultCommand()
{
	//Fill this later
}
double PowerBoard::GetVoltage()
{
	powerboard->GetVoltage();
}
	
double PowerBoard::GetTemperature()
{
	powerboard->GetTemperature();
}

double PowerBoard::GetCurrent(uint8_t channel)
{
	powerboard->GetCurrent(channel);
}

double PowerBoard::GetTotalCurrent()
{
	powerboard->GetTotalCurrent();
}

double PowerBoard::GetTotalPower()
{
	powerboard->GetTotalPower();
}

double PowerBoard::GetTotalEnergy()
{
	powerboard->GetTotalEnergy();
}

void PowerBoard::ResetTotalEnergy()
{	
	powerboard->ResetTotalEnergy();
}

void PowerBoard::ClearStickyDefaults()
{
	powerboard->ClearStickyDefaults();
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