#include <iostream>
#include <string>

#include "Table.h"
 
using namespace std;

// constructor
Table::Table(string nm, string wd) : Furniture(nm) {
	if ((wd.compare("Pine") == 0) || 
		(wd.compare("Oak") == 0) ||
		(wd.compare("Queen") == 0) ||
		(wd.compare("King") == 0)) 
	{
		wood = wd;
		Table::readDimensions();
	}
	else {
		cout << "\t" << "Wood type must be one of: 'Pine' or 'Oak'"
		<< endl;
	}
}

// destructor
Table::~Table() {}

/*
*  Function: print
*
*  Purpose:  print information about the table to stdout
*/
void Table::print() {
	Furniture::print();
	cout <<  "\t" << wood << " wood" << endl;
}
