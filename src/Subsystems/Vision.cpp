#include "Vision.h"
#include "RobotMap.h"

Vision::Vision() :
		Subsystem("Vision")
{
	lcam = new I2C(I2C::kOnboard, 2);
}

void Vision::InitDefaultCommand()
{

}

void Vision::updateVision()
{
	static uint8_t* data = new uint8_t[7];
	for (int i = 0; i < 7; i++)
		data[i] = 0;

	lcam->ReadOnly(7, data);
	printf("I2C: %u\n", data[0]);
	printf("I2C: %u\n", data[1]);
	printf("I2C: %u\n", data[2]);
	printf("I2C: %u\n", data[3]);
	printf("I2C: %u\n", data[4]);
	printf("I2C: %u\n", data[5]);
	printf("I2C: %u\n", data[6]);
}

uint32_t Vision::convertToInteger(uint8_t bytes[]) {
	uint32_t result;
	result = (bytes[0] << 24 |
			  bytes[1] << 16 |
			  bytes[2] << 8 |
			  bytes[3]);
	return result;
}

float Vision::convertToFloat(uint8_t bytes[]) {
	//Found this on stack overflow: means it's correct
	float f;
	memcpy(&f, &bytes, sizeof(f));
	return f;
}


/*
 * Gets the aspect ratio of the bounding box of the
 * tote
 *
 * camera: The camera numbers (0 is the left, 1 is the right)
 * priority: The which size box (0 will choose first largest, 1 will choose second largest)
 */

uint32_t getRatio(uint32_t camera, uint32_t priority) {

}



// Put methods for controlling this subsystem
// here. Call these from Commands.
