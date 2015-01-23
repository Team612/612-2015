#include "PowerBoard.h"
#include "../RobotMap.h"

PowerBoard::PowerDistributionPanel() :
		Subsystem("PowerDistributionPanel");
{

}

void ExampleSubsystem::InitDefaultCommand()
{
	//Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


PowerDistributionPanel()
{
	PowerDistributionPanel();
}
	

void InitTable(ITable* subTable)
{
	InitTable(subTable);
}
	

void InitDefaultCommand()
{
	//Fill this later
}
double GetVoltage()
{
	GetVoltage();
}
	
double GetTemperature()
{
	GetTemperature();
}

double GetCurrent(uint8_t channel)
{
	GetCurrent(channel);
}

double GetTotalCurrent()
{
	GetTotalCurrent();
}

double GetTotalPower()
{
	GetTotalPower();
}

double GetTotalEnergy()
{
	GetTotalEnergy();
}

void ResetTotalEnergy()
{	
	ResetTotalEnergy();
}

void ClearStickyDefaults()
{
	ClearStickyDefaults();
}

void UpdateTable()
{
	UpdateTable();
}

void StartLiveWindowMode()
{
	StartLiveWindowMode();
}

void StopLiveWindowMode()
{
	StopLiveWindowMode();
}

ITable* GetTable()
{
	GetTable();
}
