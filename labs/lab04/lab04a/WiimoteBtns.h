/*
 * @project	lab04
 * @file	WiimoteBtns.h
 * @author	Matthew Springer
 * @created	February 7, 2017
 * @purpose	Header file for class WiimoteBtns
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

/*
// output codes for each button
const int 1_code = 1;
const int 2_code = 2;

const int a_code = 48;
const int b_code = 49;

const int home_code = 60;

const int up_code = 103;
const int left_code = 105;
const int right_code = 106;
const int down_code = 108;

const int plus_code = 151;
const int minus_code = 156;
*/

class WiimoteBtns {

private:

	int fd;

public:

	WiimoteBtns();

	~WiimoteBtns();

	void Listen();

	void ButtonEvent(int code, int value);
};
