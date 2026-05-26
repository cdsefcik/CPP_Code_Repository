/*
K - means_Clustering.cpp : Defines the entry point for the application.

Author: Christopher Sefcik

Program Use: Optimized version of K-means Clustering

Development Notes:
1: Need to take in the input file, parse it and create two vector of vectors, one for the identifer fields, the second for the
clustering data.

2:Parameters to run the program:
A: Does it have a header row
B: Number of columns from the left that are considered keys, but are not run through the analysis exe:0 = no columns, 1, 2, 3
C: The number of clusters
D: Is the program going to be run from the command line or is it going to be exected via another program?

3: Things to add
A: An option to deliver the cluster coordinates do the program sones need to be run everytime to make a classification.
B: A minimization function that calculates what the optimal amount of clusters is, the hightest jump in minimized distances.
C: Might need to add a clause if the radius is zero while there is data, then a default radius will be used.
D: A case statement that if parameters are empty default to cmd line, if 1 0r 2, the switch to cmd or parameter based to run from Python or directy from the command line.


How to run program:

*/ 

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "K-means_Clustering.h"
#include "importData.h"
#include <vector>
#include <sstream>
#include <utility>
#include <cmath>
#include <numeric>
#include <limits>
#include <stdexcept>
#include "records.h"


using namespace std;
namespace fs = std::filesystem;

// --- Utility: Euclidean Distance ---
//Function Instructions:
/*
The function takes two vectors of doubles(a and b) by const reference — meaning :
The function won’t modify them.
Passing by reference avoids copying large vectors.
Checks that both vectors have the same number of elements.
If not, it throws an exception to prevent undefined behavior.
Uses the STL algorithm std::inner_product to compute the sum of squared differences efficiently.
a.begin(), a.end() — iterate through vector a.
b.begin() — simultaneously iterate through vector b.
0.0 — the initial value for the sum.
std::plus<>() — how to combine results (addition).
Lambda function — defines what to multiply each pair by:

(𝑥−𝑦)∗(𝑥−𝑦) (x−y)∗(x−y), i.e., the squared difference.

After this line, sum holds the total of squared differences.
*/

double euclideanDistance(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be of equal length");
    }

    double sum = std::inner_product(
        a.begin(), a.end(), b.begin(), 0.0,
        std::plus<>(),
        [](double x, double y) { return (x - y) * (x - y); }
    );

    return std::sqrt(sum);
}

/*END OF EUCLIDEAN DISTANCE FUNCTION*/

//The acrual algorithm
vector<record> kmeansAlgorithm(std::vector<record> &recordNodes, std::vector<clusterNode> &clusterNodes) {
    
    //Notes, I am going to store all the algorithm details in the record node. The cluster is just going to be a reference point.

    //calculate the distances 
    for(const auto &recordNode : recordNodes){
    
    
    }

    return recordNodes;
};


int main(int argc, char** argv)
{

//VARIABLES:
    
    int k = 3;

   importData myData("2");
    
   auto [converted, failed] = myData.dataForProcess(); //Note Creates two vectors of vectors: convertedRecords and failedRecords.
   vector<string> headerData = myData.getheaderRowData();
   vector<vector<string>> identifierColumns = myData.getidentifierCols();
        
        for (const auto& header: headerData) {
        cout << header << endl;
        }

        cout << endl;

        for (const auto& record : identifierColumns) {
            for (const auto& field : record) {
                cout << field << " ";
            }
            cout << " " << endl;
        }
     
        cout << endl;


        cout << "These are the converted records: " << endl;
        for (const auto& record : converted) {
            for (const auto& field : record) {
                cout << field << " ";
            }
            cout << " " << endl;
        }
        cout << "These are the failed records: " << endl;
        for (const auto& record : failed) {
            for (const auto& field : record) {
                cout << field << " ";
            }
            cout << " " << endl;
        }

        //TEST CLUSTER COORDINATES
        clusters cluster(converted);

        cout << " " << endl;

       //Test Minimum Values:

        //clusters::clusters(converted);
        
        vector<double> minimumValues = cluster.getMinimumValues();
        cout << "These are the minimum Values: " << endl;
        for (const auto& record : minimumValues) {
                cout << record << " ";
        }

        cout << " " << endl;

        vector<double> maximumValues = cluster.getMaximumValues();
        cout << "These are the maximum Values: " << endl;
        for (const auto& record : maximumValues) {
            cout << record << " ";
        }

        cout << " " << endl;
        vector<double> centroidValues = cluster.getcentroidCalculation();
        cout << "The centroid values are: " << endl;
        for (const auto& record : centroidValues) {
            cout << record << " ";
        }

        cout << " " << endl;
        double radius = cluster.getRadiusCalculation();
        cout << "The radius value is: " << radius << endl;

        cout << " " << endl;
        cout << "These are the cluster values: " << endl;
        clusterNode node1(1);
        for (const auto& value : node1.getRandomPointOnSphere()) {
            std::cout << value << " ";
        }
        cout << " " << endl;
        clusterNode node2(2);
        for (const auto& value : node2.getRandomPointOnSphere()) {
            std::cout << value << " ";
        }
        cout << " " << endl;
        clusterNode node3(3);
        for (const auto& value : node3.getRandomPointOnSphere()) {
            std::cout << value << " ";
        }
        cout << " " << endl;
        
 //This sets up all the record values in an vector

        std::cout << "These are the record details " << endl;
        std::cout << "" << endl;

        std::vector<record> recordNodes;

        for (const auto& rec : converted) {
            record recordNode(rec);
            std::cout << recordNode.getTotalRecords() << recordNode.getRecordNumber() << endl;
            recordNodes.push_back(recordNode);   // works correctly now
        }
        std::cout << "These are the total records within the record nodes" << endl;
        std::cout << " " << endl;
        std::cout << "\nRecords stored in recordNodes:\n";
        for (const auto& rec : recordNodes) {
            std::cout << rec << "\n";
        }

   //This tests all the eucidean distances:
        std::cout << "These are the euclidean distances: " << endl;
        std::cout << " ";

        for (const auto& record : recordNodes) {
            std::cout << "Euclidean Distance: " << euclideanDistance(record.getrecordCoordinates(), node1.getcentroidCalculation()) << endl;
        }
        std::cout << " ";
//Output File Code:
	return 0;
}
