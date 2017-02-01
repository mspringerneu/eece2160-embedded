g*
 *  Project: EECE 2160 Lab #03 Part 3
 *  Author:  Matthew Springer
 *  Date:    February 1, 2017
 */

#include <iostream> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/mman.h> 
#include <cmath>
using namespace std;

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

struct PushButtonConfig {
       int left;
       int right;
       int up;
       int down;
       int center;
};

class ZedBoard
{
      int fd;
      char *pBase;
      int * counter;
      PushButtonConfig *pbConfig;
      
      private:

      /** 
       * Write a 4-byte value at the specified general-purpose I/O location. 
       * 
       * @param  pBase  Base address returned by 'mmap'. 
       * @param  offset	Offset where device is mapped. 
       * @param  value	Value to be written. 
       */ 
      void registerWrite(int offset, int value) 
      { 
      	* (int *) (this->pBase + offset) = value; 
      } 
      
      /** 
       * Read a 4-byte value from the specified general-purpose I/O location. 
       * 
       * @param  pBase  Base address returned by 'mmap'. 
       * @param  offset	Offset where device is mapped. 
       * @return        Value read. 
       */ 
      int registerRead(int offset) 
      { 
      	return * (int *) (this->pBase + offset); 
      } 
      
      /** 
       * Initialize general-purpose I/O 
       *  - Opens access to physical memory /dev/mem 
       *  - Maps memory at offset 'gpio_address' into virtual address space 
       * 
       * @param  fd	File descriptor passed by reference, where the result 
       *				    of function 'open' will be stored. 
       * @return		Address to virtual memory which is mapped to physical, 
       *          	or MAP_FAILED on error. 
       */ 
      char * initialize() 
      { 
      	this->fd = open( "/dev/mem", O_RDWR); 
      	return (char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED, 
      			this->fd, gpio_address); 
      } 
      
      /** 
       * Close general-purpose I/O. 
       * 
       * @param  pBase Virtual address where I/O was mapped. 
       * @param  fd	   File descriptor previously returned by 'open'. 
       */ 
      void finalize() 
      { 
      	munmap(this->pBase, gpio_size); 
      	close(this->fd);
      } 
      
      /** Changes the state of an LED (ON or OFF)
       * @param	 pBase	base address of I/O
       * @param	 ledNum	LED number (0 to 7)
       * @param	 state
      State to change to (ON or OFF)
      */
      void write1Led(int ledNum, int state) {
      	int ledOffset = 0x12C + (ledNum * 0x004);
      	this->registerWrite(ledOffset, state);
      }
      
      /** Reads the value of a switch
       * - Uses base address of I/O
       * @param	 pBase      base address of I/O
       * @param	 switchNum 	Switch number (0 to 7)
       * @return            switch value read
      */
      int read1Switch(int switchNum) {
      	int switchOffset = 0x14C + (switchNum * 0x004);
      	return this->registerRead(switchOffset);
      }
      
      /** Reads all the switches and returns their value in a single integer. 
       * 
       * @param  pBase Base address for general-purpose I/O 
       * @return A value that represents the value of the switches 
       */ 
       int readAllSwitches() {
           int sum = 0;
           int length = 8;
           bool converting = true;
           for (int i = 0; i < length; i++) {
               int place = pow(2, i);
               sum += place * this->read1Switch(i);
           }
           cout << "The integer representation of the current switch configuration is: " << sum << endl;
           return sum;
      }
      
      /** Reads the value of a push button
       * - Uses base address of I/O
       * @param	 pBase      base address of I/O
       * @param	 buttonNum 	push button number (0 to 4)
       *                    0 - left
       *                    1 - right
       *                    2 - up
       *                    3 - down
       *                    4 - center
       * @return            button value read
      */
      int read1Button(int buttonNum) {
      	int buttonOffset = 0x16C + (buttonNum * 0x004);
      	return this->registerRead(buttonOffset);
      }
      
      public:
      
      /** Changes the state of an LED (ON or OFF) to represent a given int in binary
       * @param	 pBase	base address of I/O
       * @param	 numVal the number (0-255) to be represented in binary on the LEDs
       * @param	 state
      State to change to (ON or OFF)
      */
      void writeAllLeds(int numVal) {
           int remainder = numVal;
           int length = 8;
           int * binaryRep = new int[length];
           bool converting = true;
           for (int i = length - 1; i >= 0; i--) {
               if (converting) {
                   int place = pow(2, i);
                   if (remainder >= place) {
                      // cout << "Led #" << i << ": 1" << endl;
                      binaryRep[i] = 1;
                      remainder = remainder - place;
                      if (remainder == 0) {
                         converting = false;
                      }
                   }
                   else {
                        // cout << "Led #" << i << ": 0" << endl;
                        binaryRep[i] = 0;
                   }
               }
               else {
                    // cout << "Led #" << i << ": 0" << endl;
                    binaryRep[i] = 0;
               }
           }
           for (int j = 0; j < length; j++) {
               this->write1Led(j, binaryRep[j]);
           }
           delete [] binaryRep;
      }
      
      /** Reads the current button configuration and modifies the given counter if any are pressed. 
       * 
       * @param  pBase Base address for general-purpose I/O
       * @param  config the current button state configuration
       * @param  counter the integer to adjust
       */ 
      void pushButtonGet() {
           int left, right, up, down, center, currentNum;
           left = this->read1Button(0);
           right = this->read1Button(1);
           up = this->read1Button(2);
           down = this->read1Button(3);
           center = this->read1Button(4);
           currentNum = *this->counter;
           
           if (this->pbConfig->left == 0 && left == 1) {
              *this->counter = min(255, currentNum << 1);
              cout << "The current value of the counter is: " << *counter << endl;
           }
           this->pbConfig->left = left;
           
           if (this->pbConfig->right == 0 && right == 1) {
              *this->counter = max(0, currentNum >> 1);
              cout << "The current value of the counter is: " << *counter << endl;
           }
           this->pbConfig->right = right;
           
           if (this->pbConfig->up == 0 && up == 1) {
              *this->counter = min(255, currentNum + 1);
              cout << "The current value of the counter is: " << *counter << endl;
           }
           this->pbConfig->up = up;
           
           if (this->pbConfig->down == 0 && down == 1) {
              *this->counter = max(0, currentNum - 1);
              cout << "The current value of the counter is: " << *counter << endl;
           }
           this->pbConfig->down = down;
           if (this->pbConfig->center == 0 && center == 1) {
              *this->counter = this->readAllSwitches();
              cout << "The current value of the counter is: " << *counter << endl;
           }
           this->pbConfig->center = center;
      }
      
      int getCounter() {
          return *this->counter;
      }
      
      ZedBoard() {
          // Initialize 
        	this->pBase = this->initialize(); 
        	// Check error 
        	if (this->pBase == MAP_FAILED) 
        	{ 
        		cerr << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
        		exit(1); // Returns 1 to the operating system;	
        	}	 
        	 
        	// ************** Put your code here **********************
          this->counter = new int;
          *this->counter = this->readAllSwitches();
          this->pbConfig = new PushButtonConfig;
          this->pbConfig->left = 0;
          this->pbConfig->right = 0;
          this->pbConfig->up = 0;
          this->pbConfig->down = 0;
          this->pbConfig->center = 0;
      }
      
      ~ZedBoard() {
          this->finalize();
          delete this->pBase;
          delete this->counter;
          delete this->pbConfig;
      }
           
};



/** 
 * Main function to interact with I/O Interfaces
 */
int main() 
{ 
  ZedBoard * zb = new ZedBoard();
  cout << "The current value of the counter is: " << zb->getCounter() << endl;
  while (true) {
        zb->pushButtonGet();
        zb->writeAllLeds(zb->getCounter());
  }
  
  delete zb;
 
  return 0;
}
