#include "PowerBoard.h"
#include "../RobotMap.h"

PowerBoard::PowerDistributionPanel() :
		Subsystem("PowerDistributionPanel");
{
	pdb = new PowerDistributionPanel();
}

void PowerBoard::InitDefaultCommand()
{
	//Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


PowerDistributionPanel()
{
	pdb->PowerDistributionPanel();
}
	

void InitDefaultCommand()
{
	//Fill this later
}
double GetVoltage()
{
	pdb->GetVoltage();
}
	
double GetTemperature()
{
	pdb->GetTemperature();
}

double GetCurrent(uint8_t channel)
{
	pdb->GetCurrent(channel);
}

double GetTotalCurrent()
{
	pdb->GetTotalCurrent();
}

double GetTotalPower()
{
	pdb->GetTotalPower();
}

double GetTotalEnergy()
{
	pdb->GetTotalEnergy();
}

void ResetTotalEnergy()
{	
	pdb->ResetTotalEnergy();
}

void ClearStickyDefaults()
{
	pdb->ClearStickyDefaults();
}

void UpdateTable()
{
	pdb->UpdateTable();
}

void StartLiveWindowMode()
{
	pdb->StartLiveWindowMode();
}

void StopLiveWindowMode()
{
	pdb->StopLiveWindowMode();
}