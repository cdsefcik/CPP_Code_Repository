#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
*This demonstrates the use of vectors.
*Use the ctl z character then press enter to terminate the input stream.
*
*/

inline void keep_window_open() {
	char ch; cin >> ch;
}

int main() {

	vector<string> words;
	string temp;
	while (cin >> temp) { //Reads input from the user until terminated.
		words.push_back(temp); //Pushes the input from the user into the vector.
	}

	cout << "Number of words: " << words.size() << endl;

	sort(words.begin(), words.end()); //Sorts the vector using the parameters begin and end, which provides the start and end of the vector.

	//Print Vector
	for (int i = 0; i < words.size(); i++) {
		if (i == 0 || words[i - 1] != words[i]) { //Is this a new word?
			cout << words[i] << "\n"; 
		}
	}

		return EXIT_SUCCESS;
};
