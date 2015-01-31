#ifndef Encoder_H
#define Encoder_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveEncoder: public Subsystem
{
private:
	Encoder* encoders[4];
public:
	DriveEncoder();
	virtual ~DriveEncoder();
	void InitDefaultCommand();

	int32_t getSpins(uint32_t);
	/*Gets the spins of the corresponding motor
	 * 0 = Left-Rear Motor
	 * 1 = Left-Front Motor
	 * 2 = Right-Rear Motor
	 * 3 = Right-Front Motor
	 */

	double getDistance(uint32_t);
	//Gets distance since the last reset of the corresponding encoder (see list above)

	double getRate(uint32_t);
	//Gets rate of the corresponding encoder (see list above)

	void reset();
	//Resets all encoders

	void reset(uint32_t);
	//Resets the corresponding encoder

};

#endif
