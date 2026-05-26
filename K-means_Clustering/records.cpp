#include "records.h"

int record::TotalRecords = 0;

record::record(const std::vector<double> &coords) : recordCoordinates(coords) {
    this->recordNumber = TotalRecords++;
}

std::vector<double> record::getrecordCoordinates() const {
    return recordCoordinates;
}

//Get record number
int record::getRecordNumber() const {
    return recordNumber;
};

// ? Definition of operator<<   
std::ostream& operator<<(std::ostream& os, const record& rec) {
    os << "[ ";
    for (double val : rec.recordCoordinates) {
        os << val << " ";
    }
    os << "]";
    return os;
}

