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
#include <cmath>
#include "ZedBoard.h"
#include "WiimoteAccel.h"

using namespace std;

class WiimoteToLed: public WiimoteAccel {

private:

    ZedBoard * zboard;
      
public:

    WiimoteToLed(ZedBoard * zb) {
        zboard = zb;
    }
    
    ~WiimoteToLed() {
    	delete zboard;
    }
    
    void AccelerationEvent(int code, short value) {
        int boundedVal, valIndex, newVal;
        newVal = value;
        if (code == 3) {
        	int * vals = new int[9]{0, 1, 3, 7, 15, 31, 63, 127, 255};
            boundedVal = abs(max(-100, min(100, newVal)));
            valIndex = (8 * boundedVal) / 100;
            cout << "Acceleration value " << boundedVal << " lights up " << valIndex << " LEDs" << endl;
            zboard->WriteAllLeds(vals[valIndex]);
            delete [] vals;
        }
    }
};
 
/**
 * Main operates the Zedboard LEDs and switches
 */
int main()
{
    // Instantiate ZedBoard object statically
    ZedBoard zed_board;
    // Instantiate WiimoteToLed object statically, passing a pointer to the
    // recently created ZedBoard object.
    WiimoteToLed wiimote_to_led(&zed_board);
    // Enter infinite loop listening to events. The overridden function
    // WiimoteToLed::AccelerationEvent() will be invoked when the user moves
    // the Wiimote.
    wiimote_to_led.Listen();
    // Unreachable code, previous function has an infinite loop
    return 0;
}