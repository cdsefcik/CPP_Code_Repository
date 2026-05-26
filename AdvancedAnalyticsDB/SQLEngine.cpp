#include "Header.h"
#include <stack>


class SQLEngine {
private:
	std::string SQLStatement;
	std::stack<std::string> keywords;      //For SELECT, FROM, WHERE
	std::stack<std::string> identifiers;   //For name, users, age 
	std::stack<std::string> operators;     //For >, =, etc
	std::stack<std::string> literals;       //For 18,

//Data Definition Lanaguage (DDL)
//CREATE
//ALTER
//DROP
//TRUNCATE
	std::string DDLKeywords[2] = {"CREATE", "DATABASE"};


//Data Manipulation Language (DML)

//Data Query Language (DQL)

//Data Control Lanaguage (DCL)

//Transaction Control Language (TCL)


public:

	SQLEngine() {

	}

	SQLEngine(const std::string& sqlCommand):SQLStatement() {

    }



};