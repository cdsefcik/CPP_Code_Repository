#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//Steps
	//Open File
	ifstream infile;
	infile.open("File3.txt");
		//If file does not open, display message
	if (!infile)
		cerr << "\nCan't open File3.txt\n\n";
	//else(if file opens)...
	else
		cout << "\nFile opened successfully";
	
	//Display error bit values using functions
	cout << "Error State = " << infile.rdstate();//0 for no error while opening file.
	cout << "\ngood() = " << infile.good(); //0 = false(error)
	cout << "\neof() = " << infile.eof();
	cout << "\ninfail() = " << infile.fail() << "\n\n"; //0 = no error(not failed)
	//Close file

	infile.close();

	system("pause");
	return 0;
}