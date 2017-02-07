/**
 * @file   ZedBoard.cpp
 * @author John Kimani (j.kimani@neu.edu)
 * @date   October, 2016
 * @brief  Process GPIO input and output for the Zedboard.
 *
 * Contains a ZedBoard class that opens GPIO ports through 
 * memory-mapping for reading switches and push buttons and 
 * writing to LEDs
 */
 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>

#include "ZedBoard.h"

using namespace std;

/**
 * Constructor Initialize general-purpose I/O
 *  - Opens access to physical memory /dev/mem
 *  - Maps memory at offset 'gpio_address' into virtual address space
 *
 * @param  None	Default constructor does not need arguments.
 * @return	None Default constructor does not return anything.
 */
ZedBoard::ZedBoard(){
	cout << "\nStarting...." << endl;
	dummyValue = 99;
	/* // Uncomment this block of code when connected to the Zedboard
	fd = open( "/dev/mem", O_RDWR);
	pBase = (char *) mmap(NULL,gpio_size,PROT_READ | PROT_WRITE,
	        MAP_SHARED,fd,gpio_address);
	// Check error 
	if (pBase == MAP_FAILED)
	{
		cerr << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
		exit(1); // Returns 1 to the operating system;
	}
	*/	
}
/**
 * Destructor to close general-purpose I/O.
 * - Uses virtual address where I/O was mapped.
 * - Uses file descriptor previously returned by 'open'.
 *
 * @param  None	Destructor does not need arguments.
 * @return	None Destructor does not return anything.
 */
ZedBoard::~ZedBoard(){
	/* munmap(pBase, gpio_size);
	close(fd);
	*/	
	cout << "\nTerminating...." << endl;
}
/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @parem offset	Offset where device is mapped.
 * @param value		Value to be written.
 */
void ZedBoard::RegisterWrite(int offset, int value)
{
	//* (int *) (pBase + offset) = value;
	dummyValue = value;
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @param offset	Offset where device is mapped.
 * @return		Value read.
 */
int ZedBoard::RegisterRead(int offset)
{
	//return * (int *) (pBase + offset);
	return dummyValue;
}

/**
 * Changes the state of an LED (ON or OFF)
 *
 * - Uses base address of I/O
 * @param ledNum	LED number (0 to 7)
 * @param state	State to change to (ON or OFF)
 */
void ZedBoard::Write1Led(int ledNum, int state)
{
	cout << "\nWriting to LED " << ledNum << ": LED state = " << state << endl;
	//RegisterWrite(gpio_led1_offset + (ledNum * 4), state);
}

/**
 * Show lower 8 bits of integer value on LEDs
 *
 * - Calls Write1Led() to set all LEDs 
 * @param value	Value to show on LEDs
 */
void ZedBoard::WriteAllLeds(int value)
{
	cout << "\nWriting to all LEDs...." << endl;
	for(int i = 0; i < 8; i++) {// write to all LEDs
		Write1Led(i, (value / (1<<i)) % 2);
	}
}

/**
 * Reads the value of a switch
 *
 * - Uses base address of I/O
 * @param switchNum	Switch number (0 to 7)
 * @return		Switch value read
 */
int ZedBoard::Read1Switch(int switchNum)
{
	cout << "\nReading Switch " << switchNum << endl;
	//return RegisterRead(gpio_sw1_offset + (switchNum * 4));
	return switchNum;
}

/**
 * Reads the switch values into a decimal integer
 *
 * - Calls Read1Switch() to read all switches 
 * @return		Switches' value read
 */
int ZedBoard::ReadAllSwitches()
{
	int switchValue = 0;
	cout << "\nReading all switches...." << endl;
	for(int i = 7; i >= 0; i--) {// read all switches
		switchValue = (switchValue << 1) + Read1Switch(i);
	}
	return switchValue;
}