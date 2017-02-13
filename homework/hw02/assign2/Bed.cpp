/*
 *  @file   Bed.cpp
 *  @author Matthew Springer
 *  @date   February 7, 2016
 */


#include <iostream>
#include <string>

#include "Bed.h"
 
using namespace std;

// constructor
Bed::Bed(string nm, string sz) : Furniture(nm) {
	if ((sz.compare("Twin") == 0) || 
		(sz.compare("Full") == 0) ||
		(sz.compare("Queen") == 0) ||
		(sz.compare("King") == 0)) 
	{
		bedSize = sz;
		Bed::readDimensions();
	}
	else {
		cout << "\t" << "Bed size must be one of: 'Twin', 'Full', 'Queen', or 'King'"
		<< endl;
	}
}

// destructor
Bed::~Bed() {}

/*
*  Function: print
*
*  Purpose:  print information about the bed to stdout
*/
void Bed::print() {
	Furniture::print();
	cout <<  "\t" << bedSize << " size" << endl;
}
