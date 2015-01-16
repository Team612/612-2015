// Benjamin Ward, Jan 13, 2015

#ifndef SRC_DATALOGGING_H_
#define SRC_DATALOGGING_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>

typedef std::string string;

class DataLogging
{
public:
	DataLogging();
	~DataLogging();
	short Log(char*);

private:
	string* bufferedText;
	int bufferSize;
	const int maxBufferSize = 64;
	void writeBuffer();
	int fileNumber = 0;
	const string fileName = "DataLog";
	std::ofstream file;
	string getTime();
	time_t rawtime;
	struct tm* timeinfo;

};

#endif /* SRC_DATALOGGING_H_ */
