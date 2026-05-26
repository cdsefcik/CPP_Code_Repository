#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
namespace fs = std::filesystem;



vector<vector<string>> inputFile() {
    vector<vector<string>> returnData;
    vector<string> records;

    string folder = "Data";  // FIXED

    try {
        if (!fs::exists(folder)) {
            cerr << "Folder does not exist: " << folder << endl;
            return {};
        }

        cout << "Current path: " << fs::current_path() << endl;

        for (const auto& entry : fs::directory_iterator(folder)) {
            if (entry.is_regular_file()) {
                string filename = entry.path().string();
                cout << "Reading file: " << filename << endl;

                ifstream file(filename);
                if (!file) {
                    cerr << "Could not open file: " << filename << endl;
                    continue;
                }

                string line;
                while (getline(file, line)) {
                    records.push_back(line);
                }
            }
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    for (const auto& record : records) {
        stringstream ss(record);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        returnData.push_back(tokens);
    }

    return returnData;
}