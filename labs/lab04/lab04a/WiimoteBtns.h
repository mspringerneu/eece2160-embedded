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

class WiimoteBtns {

private:

	int fd;

public:

	WiimoteBtns();

	~WiimoteBtns();

	void Listen();

	void ButtonEvent(int code, int value);
};
