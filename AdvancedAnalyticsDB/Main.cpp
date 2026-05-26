#include <iostream>
#include <string>
#include "Header.h"
#include <filesystem>									

using namespace Statistics;

namespace cmdLine {

	//This is the first command request:
	
	int request1(std::vector<std::vector<std::string>>& rawData) {
		int running = 1;
		do {

			int proceedLevel1 = 0;
			std::cout << "How do you want to proceed? Enter 0 to exit data management. " << std::endl;
			std::cout << "1: Read new data. " << std::endl;
			std::cout << "2: Create Database. " << std::endl;
			std::cin >> proceedLevel1;

			switch (proceedLevel1) {
			case 0:
				std::cout << "Exiting Data Management: " << std::endl;
				break;
			case 1:
				std::cout << "Reading in new data: " << std::endl;
				std::filesystem::create_directories("Data");
				rawData = inputFile(); //Raw Data
				break;
			case 2:
				std::cout << "Creating Database: " << std::endl;
				std::filesystem::create_directories("Database");
				break;
			default:
				std::cout << "Not a valid entry: " << std::endl;
			}

			if (proceedLevel1 == 0) {
				running = 0;
			}

		} while (running);
		return running;
	}

	int Request2(std::vector<std::vector<std::string>>& rawData) {
		std::cout << "Test Function: " << std::endl;
		//Convert Data to double
		//#######################################################
		//TEST CODE

		//std::cout << "Value: " << rawData[69] << std::endl;
		for (int i = 0; i < rawData[70].size(); i++) {
			std::cout << "Value ISOLATED: " << "i " << i << rawData[70][i] << " ";
		}

		for (const auto& values : rawData) {
			std::cout << "Value: " << values[0] << std::endl;
		}

		/*
		std::vector<double> doubleVec;
		for (const auto& row : rawData) {
			if (row.size() > 4) {
				try {
					doubleVec.push_back(std::stod(row[4]));
				}
				catch (const std::exception&) {
					std::cout << "Value: " << row[4] << std::endl;
					// skip bad data
				}
			}
		}
		*/
		std::vector<double> doubleVec;
		for (int i = 0; i < rawData.size(); i++) {
			if (rawData[i].size() >= 0) {
				try {
					doubleVec.push_back(std::stod(rawData[i][0]));
				}
				catch (const std::exception&) {
					//std::cout << "Value: " << rawData[i] << std::endl;
					// skip bad data
				}
			}
		}



		//#######################################################
		std::cout << "Test Mean Function: " << Statistics::mean(doubleVec) << std::endl;

		return 1;
	}

	int Request3(std::vector<std::vector<std::string>>& rawData) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- This fixes the newline leftover \n.
		int running = 1;
		do {
		int proceedLevel1 = 0;
		std::cout << "Enter the SQL command: " << std::endl;
		std::string SQLCommand = "";
		std::getline(std::cin,SQLCommand);
		std::cout << "Here is the SQL command entered: " << SQLCommand << std::endl;

		std::cout << "Do you want to enter another SQL statement? Enter 1 to proceed, 0 otherwise:" << std::endl;
		std::cin >> proceedLevel1;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // <-- FIX

		if (proceedLevel1 == 0) {
			running = 0;
		}
		} while (running);
		return running;
	}
	
}



int main(int argc, char *argv[]) {


	std::string commandLineArg;
	
	if (argc > 1) {
		commandLineArg = argv[1];
	}

	//THIS IS THE COMMAND LINE PART OF THE PROGRAM:
	if (argc == 1 || commandLineArg == "CMDLine") {
		std::cout << "Running in Command Line Mode: " << std::endl;

		int running = 1;
		std::vector<std::vector<std::string>> rawData;
		do {
			int proceedLevel = 0;
			//Define variables:
			std::cout << "How do you want to proceed? Enter 0 to exit program: " << std::endl;
			std::cout << "Enter 1 for Data Management: " << std::endl;
			std::cout << "Enter 2 for Analytics: " << std::endl;
			std::cout << "Enter 3 for SQL command line: " << std::endl;
			std::cin >> proceedLevel;

			switch (proceedLevel) {
			case 0:
				std::cout << "Exiting Program: " << std::endl;
				break;
			case 1:
				std::cout << "Entering Data Management: " << std::endl;
				cmdLine::request1(rawData);
				break;
			case 2:
				std::cout << "Entering Analytics Management: " << std::endl;
				cmdLine::Request2(rawData);
				break;
			case 3:
				std::cout << "Entering SQL command line mode: " << std::endl;
				cmdLine::Request3(rawData);
				break;

			default:
				std::cout << "Not a valid Entry: " << std::endl;
			}
			
			if(proceedLevel == 0){
			running = 0;
			}

		} while (running);
	}

	//THIS IS THE SERVER PART OF THE PROGRAM
	else if (commandLineArg == "Server") {
		std::cout << "Running in Server Mode: " << std::endl;
		std::cout << "Enter Username: ";
		std::string Username;
		std::getline(std::cin, Username);
		std::cout << "Enter Password: ";
		std::string Password;
		std::getline(std::cin, Password);
		
	}
	//THIS IS THE PART OF THE PROGRAM FOR DIRECT RUNNING
	else if (commandLineArg == "DirectRun") {
		std::cout << "You are in direct run mode: " << std::endl;
	}
	else {
		std::cout << "An incorrect argument was entered: " << std::endl;
	}
	
	return 0;
}