#include "NetworkTables.h"

NetworkTables::NetworkTables() :
	Subsystem("NetworkTables")
{
}

NetworkTables::~NetworkTables()
{
}

void NetworkTables::InitDefaultCommand()
{
	//SetDefaultCommand(new NetworkTablesUp());
}
