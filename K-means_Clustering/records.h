// K-means_Clustering.h : Include file for standard system include files,
// or project specific include files.

/*
Author: Christopher Sefcik

Class Use: Used

Development Notes:

*/

#ifndef RECORDS_H
#define RECORDS_H
#pragma once

#include <vector>
#include <ostream>

class record {
private:
    
    std::vector<double> recordCoordinates;
    int recordNumber;
    static int TotalRecords;

    //These are the variabels that are important to running the algorithm.
    int clusterNumber = 0;                   // default: unassigned
    double distanceToCluster = std::numeric_limits<double>::infinity();
    bool changedThisCycle = true; //This tests if the record changed this K-means iteration. If all records are false, the k-means converged.

public:
    // Constructor
    record(const std::vector<double>& coords);

    // Getter for this record's coordinates
    std::vector<double> getrecordCoordinates() const;

    // Getter/setter for cluster number
    int getClusterNumber() const { return clusterNumber; }
    void setClusterNumber(int cluster) { clusterNumber = cluster; }

    //Getter/setter for distanceToCluster
    double getdistanceToCluster() const { return distanceToCluster; }
    void setdistanceToCluster(double distanceToClusterchanged) { distanceToCluster = distanceToClusterchanged; }

    //Getter/setter for changedThisCycle
    bool getchangedThisCycle() const { return changedThisCycle; }
    void setchangedThisCycle(double changedThisCycleUpdated) { changedThisCycle = changedThisCycleUpdated; }

    // Static getter for total records created
    static int getTotalRecords() { return TotalRecords; }

    //Get record number
    int getRecordNumber() const;

    // ? Friend operator<< must be declared inside the class
    friend std::ostream& operator<<(std::ostream& os, const record& rec);
};

#endif


//Method for updating the cluster number
	//Method for returning the recordCoordinates
	//Method for returning the cluster number