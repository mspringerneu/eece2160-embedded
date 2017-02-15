#include <iostream>

using namespace std;

/*
 *	@func	degreeToOnDelay
 *	@param	ser_pos	the position of the servo (0-180 degrees)
 *	@return			the time in microseconds that the PWM signal should be on
 */
 float degreeToOnDelay (float servo_pos) {
 	return (10 * servo_pos) + 600;
 }
 
 int main () {
 	float pos, cycle;
 	cout << "Please enter the current servo position (0-180): ";
 	cin >> pos;
 	cycle = degreeToOnDelay(pos);
 	cout << "The PWM signal should be on for " << cycle << " microseconds" << endl;
 	
 	return 0;
 }
