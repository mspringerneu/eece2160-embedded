/*
 * @project	lab04
 * @file	WiimoteAccel.cpp
 * @author	Matthew Springer
 * @date	February 7, 2017
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#include "WiimoteAccel.h"

using namespace std;

WiimoteAccel::WiimoteAccel() {
	fd = open("dev/input/event0", O_RDONLY);
	if (fd == -1) {
		cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

WiimoteAccel::~WiimoteAccel() {
	close(fd);
}

void WiimoteAccel::Listen() {
	// read a packet of 16 bytes from Wiimote
	char buffer[16];
	read(fd, buffer, 16);
	
	// extract code (byte 10) and value (byte 12) from packet
	int code = buffer[10];
	short acceleration = * (short *) (buffer + 12);

	// print them
	WiimoteAccel::AccelerationEvent(code, acceleration);
}

void WiimoteAccel::AccelerationEvent(int code, short value) {
	cout << "Code = " << code << ", acceleration = " << value << endl;
}
