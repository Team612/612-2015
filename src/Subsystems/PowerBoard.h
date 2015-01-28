#ifndef POWERBOARD_H
#define POWERBOARD_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class PowerBoard: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	PowerDistributionPanel* powerboard; 
public:
	PowerBoard();//Initializer for panel
	void InitDefaultCommand();//Figure this out
	double GetVoltage();//Returns input value of the PDP
	double GetTemperature();//Returns temperature of the PDP
	double GetCurrent(uint8_t channel);//Returns current of a single channel
	double GetTotalCurrent();//Total current of all monitored PDP channels (0-15)
	double GetTotalPower();//Total power drawn from the monitored PDP channels
	double GetTotalEnergy();//Total energy drawn from the monitored PDP channels
	void ResetTotalEnergy();//Reset total energy drawn from PDP
	void ClearStickyFaults();//Remove all of the fault flags on the PDP
	void UpdateTable();//Update the table for this sendable object with the latest values
	void StartLiveWindowMode();//Starts sendable object automatically respond to value changes reflect value on table
	void StopLiveWindowMode();//Ends the above
	
};

#endif
