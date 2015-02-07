#ifndef SRC_SUBSYSTEMS_NETWORK_TABLES_H_
#define SRC_SUBSYSTEMS_NETWORK_TABLES_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class NetworkTables : public Subsystem {
private:
public:
	NetworkTables();
	virtual ~NetworkTables();
	void InitDefaultCommand();
};

#endif /* SRC_SUBSYSTEMS_NETWORK_TABLES_H_ */
