/*
 * @file	WiimoteBtns.cpp
 * @author	Matthew Springer
 * @date	February 7, 2017
 * @purpose	function definitions for WiimoteBtns.h
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#include "WiimoteBtns.h"

using namespace std;

WiimoteBtns::WiimoteBtns() {
	fd = open("dev/input/event2", O_RDONLY);
	if (fd == -1) {
		cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

void WiimoteBtns::Listen() {
	while (true) {
		// read a packet of 32 bytes from Wiimote
		char buffer[32];
		read(fd, buffer, 32);

		// extract code (byte 10) and value (byte 12) from packet
		int code = buffer[10];
		int value = buffer[12];

		// print them
        // "value" refers to whether or not the button is depressed (1 if pressed, 0 if up)
		WiimoteBtns::ButtonEvent(code, value);
	}
}

void WiimoteBtns::ButtonEvent(int code, int value) {
	cout << "Code = " << code << ", value = " << value << endl;
}

WiimoteBtns::~WiimoteBtns() {
	close(fd);
}
