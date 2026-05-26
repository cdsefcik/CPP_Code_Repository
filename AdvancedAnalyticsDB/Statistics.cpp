#include <iostream>
#include <vector>
#include "Header.h"

namespace Statistics {

	double mean(const std::vector<double>& vectorRead) {

		if (vectorRead.empty()) {
			return 0.0;
		}

		double mean = 0;
		double count = vectorRead.size();

		for (const auto& element : vectorRead) {
			std::cout << " " << element << std::endl;
			mean += element;
		}

		return mean / count;
	}
}