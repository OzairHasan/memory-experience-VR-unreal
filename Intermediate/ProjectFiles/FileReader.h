#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <tuple>
class FileReader
{
public:
	FileReader(std::string filePath);

	FileReader();

	std::string getFilePath();

	void setFilePath(std::string filePath);

	std::tuple<int, std::string> getLine();

private:
	std::string filePath;
	int stateTracker;
	std::ifstream myFile;
};

