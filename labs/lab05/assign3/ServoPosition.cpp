/*
 *	@proj	lab 05 assignment #3
 *	@file	ServoPosition.cpp
 *	@author	Matthew Springer and Andreas Petrides
 *	@date	February 15, 2017
 */

#include <iostream>
#include <stdlib.h>
#include "GPIO.h"

using namespace std;

/*
 *	ServoPort#	ServoName	LinuxPort#
 *	1			Base		13
 *	2			Bicep		10
 *	3			Elbow		11
 *	4			Wrist		12
 *	5 			Gripper		0
 */
 
//	Theoretical range: 	[0.6ms, 2.4ms] = [ 0°, 180°]
//	Practical range: 	[0.7ms, 2.3ms] = [10°, 170°]

/*
 *	Return the linux port num of a servo based on a given index
 *
 *	@func	getServoPortNum
 *	@param	servo_num	the index of the desired servo
 *	@return				the linux port num of the selected servo
 */
int getServoPortNum(int servo_num)
{
	switch (servo_num)
	{
		case 1:
			return 13;
		case 2:
			return 10;
		case 3:
			return 11;
		case 4:
			return 12;
		case 5:
			return 0;
		default:
			std::cerr << "Invalid servo number, program terminating...";
			exit(1);
	}
}

/*
 *	Return the name of a servo based on a given index
 *
 *	@func	getServoName
 *	@param	servo_num	the index of the desired servo
 *	@return				the name of the selected servo
 */
string getServoName(int servo_num)
{
	switch (servo_num)
	{
		case 1:
			return "Base";
		case 2:
			return "Bicep";
		case 3:
			return "Elbow";
		case 4:
			return "Wrist";
		case 5:
			return "Gripper";
		default:
			std::cerr << "Invalid servo number, program terminating...";
			exit(1);
	}
}

/*
 *	Convert a given servo angle to the appropiate duty cycle length
 *		based on 20ms period and duty cycle in Range[3%, 12%]
 *
 *	@func	degreeToOnDelay
 *	@param	servo_pos	the position of the servo (0-180 degrees)
 *	@return				microseconds that the PWM signal should be on
 */
int degreeToOnDelay (int servo_pos) {
	return (10 * servo_pos) + 600;
}

/*
 *	Print a menu giving the user the servo selection options
 *
 *	@func	printMenu
 *	@return			None
 */
void printMenu()
{
	cout << endl << "CONTROLLABLE SERVOS" << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << "\t" << i << ".  " << getServoName(i) << endl;
	}
	cout << "Please select the servo you would like to control: ";
}

/*
 *	Get the number of degrees to rotate the servo from the user
 *		-	rotation angle constrained to Range[10° - 170°]
 *
 *	@func	getRotAng
 *	@return		the number of degrees to rotate the servo
 */
int getRotAng()
{
	int rot_ang;
	cout << "Please set the rotation angle for the servo (10° - 170°): ";
	cin >> rot_ang;
	if (rot_ang >= 10 && rot_ang <= 170)
	{
		return rot_ang;
		
	}
	else
	{
		std::cerr << "The angle you have entered is outside the range "
		<<	"[10° - 170°], program terminating...";
		exit(1);
	}
}

int main()
{
	int servo_select, port_num, rot_ang, onDelay;
	int period_len = 20000;
	//	print the menu
	printMenu();
	cin >> servo_select;
	port_num = getServoPortNum(servo_select);
	
	//	Open device file corresponding to user selection
	cout << "You have selected: " << getServoName(servo_select) << endl;
	GPIO gpio(port_num);
	
	//	Rotate the servo depending on user input
	rot_ang = getRotAng();
	onDelay = degreeToOnDelay(rot_ang);
	cout << "Rotating '" << getServoName(servo_select) << "' to " << rot_ang
	<< " degrees..." << endl;
	gpio.GeneratePWM(period_len, onDelay, 400);
	
	//	Done
	return 0;
}
