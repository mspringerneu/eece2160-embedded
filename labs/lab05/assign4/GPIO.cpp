/*
 *	@proj	lab 05 assignment #4
 *	@file	GPIO.cpp
 *	@author	Matthew Springer and Andreas Petrides
 *	@date	February 15, 2017
 */
 
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include "GPIO.h"

GPIO::GPIO(int number)
{
	// 	GPIO device files will follow the format
	//	/sys/class/gpio/gpio<NR>/value
	// 	<NR> has to be replaced with the actual device number passed as an
	// 	argument to the class constructor.
	char device_name[128];
	sprintf(device_name, "/sys/class/gpio/gpio%d/value", number);
	
	// 	Open special device file and store file descriptor in class member.
	fd = open(device_name, O_WRONLY);
	if (fd < 0)
	{
		std::cerr << "Cannot open " << device_name <<
		" - forgot sudo? \n";
		exit(1);
	}
}

GPIO::~GPIO()
{
	// Close open file descriptor
	close(fd);
}

void GPIO::GeneratePWM(int period, int pulse, int num_periods)
{
	// Generate num_periods of the PWM signal
	for (int i = 0; i < num_periods; i++)
	{
		//	Write ASCII character "1" to raise pin to 1, starting the
		//	ON cycle, then wait duration of pulse.
		write(fd, "1", 1);
		usleep(pulse);
		
		//	Write ASCII character "0" to lower pin to 0, starting the
		//	OFF cycle, then wait the rest of the period time.
		write(fd, "0", 1);
		usleep(period - pulse);
	}
}

void GPIO::GenerateVariablePWM(int period, int first_pulse, int last_pulse, int num_periods)
{ 
  int pulse_increment = (last_pulse - first_pulse) / num_periods;
  int one_sec = 100;
  
  // Start position for one second
  for (int i = 0; i < one_sec; i++)
	{
    //	Write ASCII character "1" to raise pin to 1, starting the
		//	ON cycle, then wait duration of pulse.
		write(fd, "1", 1);
		usleep(first_pulse);
   
		//	Write ASCII character "0" to lower pin to 0, starting the
		//	OFF cycle, then wait the rest of the period time.
		write(fd, "0", 1);
		usleep(period - first_pulse);
	}
 
  // Interpolation from first_pulse to last pulse by speed
	for (int i = 0; i < num_periods; i++)
	{
		int currentPulse = first_pulse + (i * pulse_increment);
    //	Write ASCII character "1" to raise pin to 1, starting the
		//	ON cycle, then wait duration of pulse.
		write(fd, "1", 1);
		usleep(currentPulse);
		
		//	Write ASCII character "0" to lower pin to 0, starting the
		//	OFF cycle, then wait the rest of the period time.
		write(fd, "0", 1);
		usleep(period - currentPulse);
	}
  
  // Final position for one second
  for (int i = 0; i < one_sec; i++)
	{
    //	Write ASCII character "1" to raise pin to 1, starting the
		//	ON cycle, then wait duration of pulse.
		write(fd, "1", 1);
		usleep(last_pulse);
   
		//	Write ASCII character "0" to lower pin to 0, starting the
		//	OFF cycle, then wait the rest of the period time.
		write(fd, "0", 1);
		usleep(period - last_pulse);
	}
}
