#include "PointCloudGenerator.h"


PointCloudGenerator::PointCloudGenerator() {}

std::vector<CloudPoint> PointCloudGenerator::getPointCloud(std::string path) {
	reader = FileReader(path);
	std::vector<CloudPoint> pointCloud;
	reader.getLine(); reader.getLine();
	while (true) {
		std::tuple<int, std::string> line = reader.getLine();
		if (std::get<0>(line) == 0) {
			break;
		}
		if (std::get<1>(line).length() < 5) {
			break;
		}
		std::stringstream s;
		s << std::get<1>(line);
		std::string word;
		std::vector<std::string> words;
		while (std::getline(s, word, ' ')) {
			words.push_back(word);
		}
		CloudPoint cp = CloudPoint(
			std::stof(words[0]),
			std::stof(words[1]),
			std::stof(words[2]),
			std::stoi(words[3]),
			std::stoi(words[4]),
			std::stoi(words[5])
			);
		pointCloud.push_back(cp);
	}
	return pointCloud;
}
