/**
 * @file   ZedMain.cpp
 * @author John Kimani (j.kimani@neu.edu)
 * @date   October, 2016
 * @brief  Process GPIO input and output for the Zedboard.
 *
 * Contains a ZedBoard class that opens GPIO ports through 
 * memory-mapping for reading switches and push buttons and 
 * writing to LEDs
 */
 
#include <iostream>
#include "ZedBoard.h"

using namespace std;
 
/**
 * Main operates the Zedboard LEDs and switches
 */
int main()
{
	// Initialize
	ZedBoard *zed = new ZedBoard();	
	
	int value = 0;
	cout << "Enter a value less than 256: ";
	cin >> value;
	cout << "value entered = " << value << endl;

	// Show the value on the Zedboard LEDs
	zed->WriteAllLeds(value);
	delete zed;
	// Done
} //end main