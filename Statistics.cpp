#include<iostream>
#include<vector>

/*
Development Notes:

*/

class Statistics {
private:
	std::vector<double> statVector;

public:
	Statistics(std::vector<double> statVector) {
		this->statVector = statVector;
	}

	//Methods
	double mean() {
		double mean = 0;
		for (int i = 0; i < this->statVector.size(); i++) {
			mean += statVector.at(i);
		}
		return mean / statVector.size();
	}
};