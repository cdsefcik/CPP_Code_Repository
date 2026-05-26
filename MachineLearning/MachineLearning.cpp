#include <iostream>
#include <vector>
#include <string>
#include <cmath>

/*
Author Christopher Sefcik

Class Use: Perform machine learning calculations.

Development Notes:
Data Member definitions:
1: StatisticsVector
Vector of vector. Each vector contains a column.
index 0: Mean
Index 1: Variance
Index 2: Third Moment
Index 3: Fourth Moment

Function Members definitions:

How to use class:
*/

class MachineLearning
{
private:
	std::vector<std::string> headers;
	std::vector<std::vector<double>> quantitativeData;
	std::vector<std::vector<double>> quantitativeDataVectors;
	std::vector<std::vector<double>>* statisticsVector = new std::vector<std::vector<double>>;

public:
	MachineLearning() {
		this->headers = headers;
		this->quantitativeData = quantitativeData;
		this->quantitativeDataVectors;
		this->statisticsVector;
	
	};

	//passing by constant reference, makes it so that this class can not modify the original object (const) and uses the
	//reference of the original object to minimize copy overhead.
	MachineLearning (const std::vector<std::string>& headers,
		             const std::vector<std::vector<double>>& quantitativeData) 
					:headers(headers),
		            quantitativeData(quantitativeData) {
		this->headers = headers;
		this->quantitativeData = quantitativeData;
		this->quantitativeDataVectors;
		this->statisticsVector;

	};

	//Get the index number from the headers for data processing.
	int getIndexNumber(std::string columnName)
	{
		for (int i = 0; i < headers.size(); i++) {
			if (columnName == headers.at(i))
			{
				return i;
			}
		}
	}

	//Create a vectors for data processing.
	void createDataVectors()
	//MUST ALLOCATE THE MEMORY WITH NEW to the quantitativeDataVectors
	{
		for (int i = 0; i < headers.size(); i++)
		{
			std::vector<double> tempVector; //= new std::vector<double>;
			std::cout << "Print i: " << i << std::endl;
			for (int j = 0; j < quantitativeData.size(); j++)
			{
				tempVector.push_back(quantitativeData.at(j).at(i));
				//quantitativeDataVectors->at(i).push_back(quantitativeData.at(j).at(i));
			}
			quantitativeDataVectors.push_back(tempVector);
		
		}
	}

	std::vector<double> getDataVector(std::string columnName)
	{
		int columnNumber = getIndexNumber(columnName);
		return quantitativeDataVectors.at(columnNumber);
	}

	//Get Data Vector

	//Calculate the percentiles

	//Calculate the mean (TEST THIS!!!)
	//Notes: Made this static so that an instance of the class does not have to be initiated to run this.
	//Use the scope resulution operator to access this function.
	static double mean(const std::vector<double>& vector) {;
		double sum{ 0 };
		for (const auto& value : vector) {
			sum += value;
		}
		return sum /= vector.size();
	}

	//Calculate the variance (TEST THIS!!!!)
	//Notes: Made this static so that an instance of the class does not have to be initiated to run this.
	//Use the scope resulution operator to access this function. 
	static double variance(const std::vector<double>& vector,double &mean) {
		double variance = 0;
		for (int i = 0; i < vector.size(); i++) {
			variance += pow((vector.at(i) - mean),2);
		}
		return variance / vector.size();
	}

	//Calculate the third moment (TEST THIS!!!!)
	//Notes: Made this static so that an instance of the class does not have to be initiated to run this.
	//Use the scope resulution operator to access this function.
	static double thirdMoment(const std::vector<double>& vector, double& mean) {
		double thirdMoment = 0;
		for (int i = 0; i < vector.size(); i++) {
			thirdMoment += pow((vector.at(i) - mean), 3);
		}
		return thirdMoment / vector.size();
	}

	//Calculate the fourth moment (TEST THIS!!!!)
	//Notes: Made this static so that an instance of the class does not have to be initiated to run this.
	//Use the scope resulution operator to access this function.
	static double fourthMoment(const std::vector<double>& vector, double& mean) {
		double fourthMoment = 0;
		for (int i = 0; i < vector.size(); i++) {
			fourthMoment += pow((vector.at(i) - mean), 4);
		}
		return fourthMoment / vector.size();
	}

	void CalculateAllStatistics() {
	
	}

	//Test for normality

};