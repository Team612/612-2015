// Benjamin Ward, Jan 13, 2015

#include "DataLogging.h"

DataLogging::DataLogging()
{
	this->bufferSize = 0;
	this->bufferedText = new string[this->maxBufferSize];

	// Initialize time-related data members
	// Get current raw time value
	time(&(this->rawtime));
	// Translate raw time value into time, taking into consideration the local time zone
	this->timeinfo = localtime(&(this->rawtime));
}
DataLogging::~DataLogging() {}

short DataLogging::Log(string textToLog)
{
	if((this->bufferSize > 0) && (textToLog != this->bufferedText[this->bufferSize-1]))
	{
		if(bufferSize < this->maxBufferSize)
		{
			this->bufferedText[bufferSize] = (string)(getTime()) + (string)(textToLog);
			this->bufferSize++;
		}
		else
		{
			this->writeBuffer();
		}
	}
	else if(this->bufferSize == 0)
	{
		this->bufferedText[bufferSize] = textToLog;
		this->bufferSize++;
	}
	else
	{
		return 1;
	}
	return 0;
}

short DataLogging::Log(string* data, int length)
{
	string message = "";
	for(int i = 0; i < length; i++)
	{
		message += data[i] + " ";
	}
	return this->Log(message);
}

// This function overload enables motor values to be logged. It requires
	// an array of SpeedControllers (aka Talons, TalonSRXs, etc) and an
	// integer representing the length of the array.
short DataLogging::Log(SpeedController* talons, int length)
{
	string message = (string)("Motor: ");
	for(int i = 0; i < length; i++)
	{
		message += (string)("Talon") + std::to_string(i) + (string)(": ")
				+ std::to_string(talons[i].Get()) + (string)(" ");
	}
	return this->Log(message);
}

// This function overload enables joystick values to be logged. It
	// requires a joystick pointer (representing a controller) and
	// logs all joystick values from it (X, Y, and Z). Note that only
	// the amount of buttons pressed is logged rather than the button
	// values themselves currently, but this could be changed based on
	// the need for this functionality.
short DataLogging::Log(Joystick* joystick)
{
	string message = (string)("Joystick: ");
	message += (string)("X Value: ") + std::to_string(joystick->GetX()) + (string)(" ");
	message += (string)("Y Value: ") + std::to_string(joystick->GetY()) + (string)(" ");
	message += (string)("Z Value: ") + std::to_string(joystick->GetZ()) + (string)(" ");
	message += "Buttons: " + joystick->GetButtonCount();
	return this->Log(message);
}

void DataLogging::writeBuffer()
{
	this->file.open(this->fileName + std::to_string(this->fileNumber) + (string)".txt");
	for(int i = 0; i < this->bufferSize; i++)
	{
		this->file << bufferedText[i] << std::endl;
	}
	this->file.close();
	this->bufferSize = 0;
}

std::string DataLogging::getTime()
{
	// Get current raw time value
	time(&(this->rawtime));
	// Translate raw time value into time, taking into consideration the local time zone
	this->timeinfo = localtime(&(this->rawtime));
	return (string)("[") + (string)(asctime(this->timeinfo)) + (string)("]");
}
