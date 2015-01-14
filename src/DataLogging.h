// Benjamin Ward, Jan 13, 2015

#ifndef SRC_DATALOGGING_H_
#define SRC_DATALOGGING_H_

#include <iostream>
#include <fstream>

class DataLogging
{
public:
	DataLogging();
	~DataLogging();
	short Log(char*);

private:
	char** bufferedText;
	unsigned int bufferSize;
	const unsigned int maxBufferSize = 64;
	void writeBuffer();
	int fileNumber = 0;
	const char* fileName = "DataLog";
	std::ofstream file;

};

#endif /* SRC_DATALOGGING_H_ */
