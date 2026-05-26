#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <String>
#include <stdexcept> // for standard exceptions like std::runtime_error

/*
Requirements:
1: Reads a text file.
2: The delimeter is tab.
3: Create a vector of vectors for how many columns there are.

*/

class ImportFiles
{
private:
    //Here are the global variables:
    std::string fileName;
    std::vector<std::vector<std::string>>table;
    std::vector<std::string> headers;
    std::vector<std::vector<double>>data;
    size_t colLength;
    size_t rowLength;

    //private methods

    //Extract the headers and values:



    //Constructor:
public:
    ImportFiles(std::string fileName)
    {
        //File name
        this->fileName = fileName;
        this->table = table;
        this->headers = headers;
        this->colLength = 0;
        this->rowLength = 0;

    }


    //Create file object
    void fileVector()
    {
        std::ifstream file;
        std::string line;
        try 
        {
            //Open the file.
            file.open(this->fileName);

            //Test if the file was opened.
            if (!file.is_open()) {
                // If not, throw an exception
                throw std::runtime_error("Could not open file");
            }
            else {
                std::cout << "The file opened successfully. " << std::endl;
                while (std::getline(file, line)) 
                {
                    std::vector<std::string>row;
                    std::stringstream ss(line);
                    std::string cell;

                    while (std::getline(ss, cell, '\t')) {
                        row.push_back(cell);
                    }
                    table.push_back(row);
                }
                file.close();
                colLength = table[0].size();
                rowLength = table.size();

                //PARSE THE FILE FOR HEADERS
                headers = table.front();

                //PARSE THE FILE FOR DATA (CURRENT, ALL DATA IS ASSUMED TO BE NUMERIC DOUBLE)
                for (const auto& row : table) 
                {
                    std::vector<double> rowConverted;
                    if (&row == &table.front()) 
                    {
                        continue;
                    }
                    else 
                    {
                
                        for (const auto& value : row)
                        {
                            double valueConverted = stod(value);
                            rowConverted.push_back(valueConverted);
                        }
                        data.push_back(rowConverted);
                    }
                    
                }

            }

        }
        catch(const std::runtime_error& error)
        {
            std::cerr << "Error: " << error.what() << std::endl;
        }
        catch (...) {
            // Catch any other types of exception not specifically handled before
            std::cerr << "An unknown error occurred." << std::endl;
        }
    }

    //Print the file
    void printFileVector()
    {
        // Print the data
        for (const auto& row : table) {
            for (const auto& cell : row) {
                std::cout << cell << "\t";
            }
            std::cout << std::endl;
        }
    }

    void printHeaders()
    {
        for (const auto& value : headers) {
            std::cout << value << "\t";
        }
    }

    void printData()
    {
        // Print the data
        for (const auto& row : data) {
            for (const auto& cell : row) {
                std::cout << cell << "\t";
            }
            std::cout << std::endl;
        }
    }

    size_t tableColSize() {
       return this->colLength;
    }

    size_t tableRowSize() {
        return this->rowLength;
    }

    std::vector<std::string> getHeaders() {
        return this->headers;
    }

    std::vector<std::vector<double>> getData() {
        return this->data;
    }

};