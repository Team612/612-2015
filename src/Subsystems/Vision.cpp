
#include "Vision.h"
#include "RobotMap.h"

Vision::Vision() :
		Subsystem("Vision")
{
	wire = new I2C(I2C::kOnboard, 2);

	cam0Data = new uint16_t[3];
	cam1Data = new uint16_t[3];

	flushData();
}

Vision::~Vision() {
	delete wire;
	delete cam0Data;
	delete cam1Data;
}

void Vision::InitDefaultCommand()
{

}

void Vision::receiveI2C()
{
	static uint8_t* buffer = new uint8_t[7];
	wire->ReadOnly(7, buffer);
	handleTransaction(buffer);
}

void Vision::flushData()
{
	for (uint32_t i = 0; i < 3; i++)
	{
		cam0Data[i] = 0;
		cam1Data[i] = 0;
	}

	cam0Received = false;
	cam1Received = false;
}

uint16_t Vision::convertTo16Int(uint8_t* array, uint32_t startIndex)
{
	uint16_t result = array[startIndex] << 8 |
					  array[startIndex + 1];

	return result;
}

void Vision::transferData(uint8_t* buffer, uint16_t* target)
{
	int targetIndex = 0;

	//Skip the byte used for the indicator
	for (uint32_t i = 1; i < 7; i += 2)
	{
		target[targetIndex] = convertTo16Int(buffer, i);
		targetIndex++;
	}
}

void Vision::handleTransaction(uint8_t* buffer)
{
	uint8_t status = buffer[0];

		switch(status) {
		case 0:
			cam0Received = true;
			transferData(buffer, cam0Data);
			break;
		case 1:
			cam1Received = true;
			transferData(buffer, cam1Data);
			break;
		case 2:
			cam0Received = false;
			break;
		case 3:
			cam1Received = false;
			break;
		}
}

bool Vision::hasReceived(Camera camera)
{
	if (camera == LEFT)
	{
		return cam0Received;
	}
	else if (camera == RIGHT)
	{
		return cam1Received;
	}
	else
	{
		return false;
	}
}

uint16_t* Vision::getRawDataArray(Camera camera)
{
	if (camera == LEFT)
	{
		return cam0Data;
	}
	else if (camera == RIGHT)
	{
		return cam1Data;
	}
	else
	{
		return 0;
	}
}

uint16_t Vision::getRaw(Camera camera, uint32_t index)
{
	return getRawDataArray(camera)[index];
}

uint16_t Vision::getBoundingX(Camera camera)
{
	return getRaw(camera, 0);
}

uint16_t Vision::getBoundingWidth(Camera camera)
{
	return getRaw(camera, 1);
}

uint16_t Vision::getBoundingHeight(Camera camera)
{
	return getRaw(camera, 2);
}

void Vision::printCameraStatistics(Camera camera)
{
	std::string strReceived = hasReceived(camera)? "true" : "false";
	std::string strCamera = camera == LEFT? "LEFT" : "RIGHT";

	printf("CAMERA %s: [Received: %s, X: %u, W: %u, H: %u]\n",
			strCamera.c_str(), strReceived.c_str(),
			getBoundingX(camera),
			getBoundingWidth(camera),
			getBoundingHeight(camera));
}

//Distancve is estimated by height
uint32_t Vision::getEstimatedDistance(Camera camera)
{
	uint16_t height = getBoundingHeight(camera);

	for (int i = 0; i < 5; i++)
	{
		//If the height is in range

		uint16_t max = distances[i + 1];
		uint16_t min = distances[i];

		if (height <= max && height >= min)
		{
			//Interpolate between distance values
			uint32_t distMin = i * 5;

			uint16_t diff = max - min;
			uint16_t measuredDiff = height - min;

			float percent = (float)measuredDiff/(float)diff;

			uint32_t distDiff = percent * 5;
			uint32_t dist = distMin + distDiff;

			return dist;
		}

	}

	if (height > distances[5])
	{
		return distances[5];
	}
	else if (height < distances[0])
	{
		return distances[0];
	}
	else
	{
		return 0; //Don't know why this would ever happen...
	}

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
