#include<iostream>
#include<string>

using namespace std;

/*
*CPP Strings
*
*/


int main() {

	//String concatenation.
	string firstName = "Dino";
	string lastName = "Brown";
	string fullName = firstName + lastName;
	//String concatenation also.
	string fullName2 = firstName.append(lastName);

	//String length, can use both, length or size.
	string str1 = "The is the string";

	cout << "The length is: " << str1.length() << endl;
	cout << "The length is: " << str1.size() << endl;

	//Take the input from the user using getline.
	string user;
	cout << "Enter the string: " << endl;
	getline(cin, user);
	cout << "The user input string is: " << user << endl;

	//Take input from the user, but also eliminate white space with the WS input manipulator.
	//Also, from the lesson, should static cast the length variable to avoid static cast errors.
	string format;
	cout << "Enter a formatted string: " << endl;
	getline(std::cin >> std::ws, format);
	cout << "The string is: " << format << endl;

	int lengthformat{ static_cast<int>(format.length()) };

	cout << "The length of the formatted string is: " << lengthformat << endl;

	//Compare two strings
	string var1 = "";
	string var2 = "";

	cout << endl << "Enter a string: ";
	getline(cin, var1);

	cout << endl << "Enter a second string: ";
	getline(cin, var2);

	if (var1.compare(var2) == 0) {
		cout << endl << "Both the strings are the same.";
	}
	else {
		cout << "Not the same\n";
	}

	//Swap two strings
	var1.swap(var2);

	cout << var1 << endl;
	cout << var2 << endl;

	//Reverse a string
	for (int i = var1.size(); i >= 0; i--) {

		cout << var1[i];
	}

	cout << "\n";
	//Delete all the vowels from the string

	for (int i = 0; i <= var1.size(); i++) {
		if (var1[i] == 'a' || var1[i] == 'e' || var1[i] == 'i' || var1[i] == 'o' || var1[i] == 'u') {
			var1[i] = ' ';
		}
	}

	//Replace a word from a string

	while (var2.find("why") != string::npos) {
		var2.replace(var2.find("why"), var2.size(), "what");
	}

	cout << var2;

	return EXIT_SUCCESS;
}
