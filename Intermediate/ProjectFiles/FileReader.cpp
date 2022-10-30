#include "FileReader.h"

FileReader::FileReader(std::string path) {
	filePath = path;
	stateTracker = 0;
	myFile.open(filePath);
}

FileReader::FileReader() {
	stateTracker = 0;
}

std::string FileReader::getFilePath() {
	return filePath;
}

void FileReader::setFilePath(std::string path) {
	filePath = path;
	myFile.open(filePath);
}

std::tuple<int, std::string> FileReader::getLine() {
	std::string myLine;
	if (myFile.is_open()) {
		if (!myFile) { // equivalent to myfile.good()
			myFile.close();
			return std::tuple<int, std::string>(0, "");
		}
		std::getline(myFile, myLine);
		return std::tuple<int, std::string>(1, myLine);
	}
	return std::tuple<int, std::string>(0, "");
}