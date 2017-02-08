/*
 * @project	lab04
 * @file	WiimoteAccel.h
 * @author	MatthewSpringer
 * @date	February 7, 2017
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

class WiimoteAccel {

private:

	int fd;

public:
	// constructor
	WiimoteAccel();

	// destructor
	~WiimoteAccel();

	void Listen();

	virtual void AccelerationEvent(int code, short value);
};
