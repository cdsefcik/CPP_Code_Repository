#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<sstream>
#include <iomanip> //For the setprecision.


using namespace std;



/*
*This program parses sentances and removes characters defined.
*
*/

inline void keep_window_open() {

    char ch; cin >> ch;

}



int main() {

    string line;
    getline(cin, line); //Read into line.
    for (int i = 0; i < line.size(); ++i) { //Replace each punctuation character.
        switch (line[i]) {
        case';':case',':case'.':case'?':case'!':
            line[i] = ' ';
        }

    }

    stringstream ss(line);   //Make adn istream ss reading from line
    vector<string>vs;
    string word;
    while (ss >> word) vs.push_back(word);

    for (int i = 0; i < vs.size(); i++) {
        cout << vs.at(i) << endl;
    }

        return EXIT_SUCCESS;
}
