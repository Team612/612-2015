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
	PowerBoard();///Construction for panel
	void InitDefaultCommand();///<Default command (none really)
	///Gets voltage input of PDP
	///@returns voltage (double)
	double GetVoltage();
	/// Gets temperature of the PDP
	double GetTemperature();
	///Returns current of specific channel
	///@param channel which channel to get current from (0-15)
	double GetCurrent(uint8_t channel);
	///Returns total current of all channels (16 total)
	double GetTotalCurrent();
	///Returns total power from all channels (16)
	double GetTotalPower();
	///Returns total energy from all channels (16)
	double GetTotalEnergy();
	///Resets energy drawn from the PDP
	void ResetTotalEnergy();
	///Removes fault flags on PDP (not sure what those are)
	void ClearStickyFaults();
	///Updates table
	///Not sure specifically what it does, this was never used
	void UpdateTable();
	///Starts sending objects diretly the live window
	///Never used also
	void StartLiveWindowMode();
	///Stops sending objects to live window
	///Also never used
	void StopLiveWindowMode();//Ends the above
};

#endif
