/**
 * @file   ZedBoard.h
 * @author John Kimani (j.kimani@neu.edu)
 * @date   October, 2016
 * @brief  Process GPIO input and output for the Zedboard.
 *
 * Contains a ZedBoard class that opens GPIO ports through 
 * memory-mapping for reading switches and push buttons and 
 * writing to LEDs
 */
 
#ifndef ZEDBOARD_H
#define ZEDBOARD_H
 
// Physical base address of GPIO 
const unsigned gpio_address = 0x400d0000; 

// Length of memory-mapped IO window 
const unsigned gpio_size = 0xff; 

const int gpio_led1_offset = 0x12C;  // Offset for LED1 
const int gpio_led2_offset = 0x130;  // Offset for LED2 
const int gpio_led3_offset = 0x134;  // Offset for LED3 
const int gpio_led4_offset = 0x138;  // Offset for LED4 
const int gpio_led5_offset = 0x13C;  // Offset for LED5 
const int gpio_led6_offset = 0x140;  // Offset for LED6 
const int gpio_led7_offset = 0x144;  // Offset for LED7 
const int gpio_led8_offset = 0x148;  // Offset for LED8 

const int gpio_sw1_offset = 0x14C;  // Offset for Switch 1 
const int gpio_sw2_offset = 0x150;  // Offset for Switch 2 
const int gpio_sw3_offset = 0x154;  // Offset for Switch 3 
const int gpio_sw4_offset = 0x158;  // Offset for Switch 4 
const int gpio_sw5_offset = 0x15C;  // Offset for Switch 5 
const int gpio_sw6_offset = 0x160;  // Offset for Switch 6 
const int gpio_sw7_offset = 0x164;  // Offset for Switch 7 
const int gpio_sw8_offset = 0x168;  // Offset for Switch 8 

const int gpio_pbtnl_offset = 0x16C;  // Offset for left push button 
const int gpio_pbtnr_offset = 0x170;  // Offset for right push button 
const int gpio_pbtnu_offset = 0x174;  // Offset for up push button 
const int gpio_pbtnd_offset = 0x178;  // Offset for down push button 
const int gpio_pbtnc_offset = 0x17C;  // Offset for center push button

// Class Definition
class ZedBoard {
private:
	char *pBase;	// virtual address where I/O was mapped
	int fd;			// file descriptor for dev memory
	int dummyValue; // for testing without a Zedboard
public:
	ZedBoard();		// Default Constructor
	~ZedBoard();	// Destructor
	void RegisterWrite(int offset, int value);
	int RegisterRead(int offset);
	void Write1Led(int ledNum, int state);
	void WriteAllLeds(int value);
	int Read1Switch(int switchNum);
	int ReadAllSwitches();
};
 
#endif