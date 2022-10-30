#pragma once

#include <string>
#include <string.h>
#include <sstream>
#include "FileReader.h"
#include "CloudPoint.h"
#include <vector>
class PointCloudGenerator
{
public:
	PointCloudGenerator();

	std::vector<CloudPoint> getPointCloud(std::string path);

private:
	FileReader reader;
	std::string filePath;
};