#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	I2C* i2c;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Vision();
	void InitDefaultCommand();

	void updateVisionRead();
	void updateVisonWrite();

	static int p1[1][1];
	static int p2[1][1];
	static int p3[1][1];
	static int p4[1][1];
};

#endif
