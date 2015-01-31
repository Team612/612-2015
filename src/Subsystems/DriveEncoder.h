#ifndef Encoder_H
#define Encoder_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveEncoder: public Subsystem
{
private:
	Encoder* encoders[4]; //A encoder array, four members for the drivetrain
public:
	DriveEncoder(); //
	virtual ~DriveEncoder(); //deconstructor
	void InitDefaultCommand();

	int32_t GetEncoderSpins(uint32_t);
	/*Gets the spins of the corresponding motor
	 * 0 = Left-Rear Motor
	 * 1 = Left-Front Motor
	 * 2 = Right-Rear Motor
	 * 3 = Right-Front Motor
	 */

	double GetEncoderDistance(uint32_t);
	//Gets distance since the last reset of the corresponding encoder (see list above)

	double GetEncoderRate(uint32_t);
	//Gets rate of the corresponding encoder (see list above)

	void ResetAllEncoders();
	//Resets all encoders

	void ResetEncoder(uint32_t);
	//Resets the corresponding encoder

};

#endif
