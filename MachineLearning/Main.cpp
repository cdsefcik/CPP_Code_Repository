#include<iostream>
#include "ImportFiles.h"
#include "MachineLearning.h"

int main()
{
	ImportFiles* files = new ImportFiles("Advertising.txt");

	files->fileVector();
	files->printFileVector();

	//Return the column size:
	std::cout << "This is the column size of the data: " << files->tableColSize() << std::endl;

	//Return the row size:
	std::cout << "This is the row size of the data: " << files->tableRowSize() << std::endl;

	//Returns the headers:
	std::cout << "These are the headers: " << std::endl;
	files->printHeaders();
	std::cout <<std::endl;

	//This is the data:
	std::cout << "This is the data: " << std::endl;
	files->printData();

	//Instantiate Machine Learning Objects:
	MachineLearning* DataProcessing = new MachineLearning(files->getHeaders(),files->getData());

	//Get header columns locations
	std::cout << "Index 1: " << DataProcessing->getIndexNumber("")<<std::endl;
	std::cout << "Index 2: " << DataProcessing->getIndexNumber("TV")<< std::endl;
	std::cout << "Index 3: " << DataProcessing->getIndexNumber("radio")<< std::endl;
	std::cout << "Index 4: " << DataProcessing->getIndexNumber("newspaper")<< std::endl;
	std::cout << "Index 5: " << DataProcessing->getIndexNumber("sales")<< std::endl;

	//Create the data vectors:
	DataProcessing->createDataVectors();
	//std::cout << "Get Data Vector: for TV" << std::endl;
	
	//std::vector<double> TVVector = DataProcessing->getDataVector("TV");
	
	//for (const auto& row : TVVector) {
	//	std::cout << row << std::endl;
	//}


	std::cout << "Get Data Vector: for TV" << std::endl;
	std::vector<double> TVVector = DataProcessing->getDataVector("TV");

	for (const auto& row : TVVector) {
		std::cout << row << std::endl;
	}


	std::cout << "Get Data Vector: for TV" << std::endl;


	std::cout << "Get Data Vector: for newspaper" << std::endl;
	
	return 0;
};