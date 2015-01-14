// Benjamin Ward, Jan 13, 2015
#include "DataLogging.h"

DataLogging::DataLogging()
{
	this->bufferSize = 0;
	this->bufferedText = new char*[this->maxBufferSize];
}
DataLogging::~DataLogging() {}

short DataLogging::Log(char* textToLog)
{
	if((this->bufferSize > 0) && (strcmp(textToLog,this->bufferedText[this->bufferSize-1]) != 0))
	{
		if(bufferSize < this->maxBufferSize)
		{
			this->bufferedText[bufferSize] = textToLog;
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
}

void DataLogging::writeBuffer()
{
	this->file.open(this->fileName + std::to_string(this->fileNumber) + ".txt");
	for(int i = 0; i < this->bufferSize; i++)
	{
		this->file << bufferedText[i] << std::endl;
	}
	this->file.close();
	this->bufferSize = 0;
}
