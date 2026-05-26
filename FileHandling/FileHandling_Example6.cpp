#include <iostream>
#include <fstream>


using namespace std;

int main() {
	
	//Using file pointers with binary files.

	const int MAX_SIZE = 10;

	int Array[MAX_SIZE];

	for (int j = 0; j < MAX_SIZE; j++) {
		Array[j] = j;
	}

	//Open the binary file.
	ofstream os("BFile.dat", ios::binary);

	//Write the complete array of integers to the binary file using write function 
	os.write(reinterpret_cast<char*>(Array), MAX_SIZE * sizeof(int)); //First paramters takes the array and creates a pointer for a character buffer, the second paramters is the size of the character buffer.

	os.close();

	ifstream is("Bfile.dat",ios::binary);

	for (int j = 0; j < MAX_SIZE; j++) {
		Array[j] = 0;
	} //Erase the data so that we can collect the data from the binary file.

	is.read(reinterpret_cast<char*>(Array), MAX_SIZE * sizeof(int));//The first paramters creates a character pointer to store the array in our character buffer "Array"

	//Print the array to the screan
	for (int j = 0; j < MAX_SIZE; j++) {
		if (Array[j] != j) {
			cout << "Wrong data is read from the file\n";
			return 1;
		}
		cout << "Array[" << j << "] = " << Array[j]<<endl;
	}

	cout << "\n\n Data is correct\n";

	is.close();

	system("pause");
	return 0;
}