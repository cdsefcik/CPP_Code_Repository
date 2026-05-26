#ifndef MYHEADER_H
#define MYHEADER_H
#pragma once

#include <vector>
#include <string>
std::vector<std::vector<std::string>> inputFile();

namespace Statistics {
	double mean(const std::vector<double>& vectorRead);
}


#endif // MYHEADER_H