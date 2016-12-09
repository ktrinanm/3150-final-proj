/*
*	@Authors: Katrina Mehring & Braden Roberts
*
*	This project is image capture triggered by motion detection using
*		a raspberry pi B+, along with camera and motion detector modules.
*/

#include <iostream>
#include "wiringPi.h"	// Used to speak to the GPIO pins
#include <cstdio> 		// Used this for testing purposes
#include <cstdlib>		// Provided use of the system command
 using namespace std; 
int main()
{
	wiringPiSetup();  // Sets up the default GPIO names/configurations
	
	pinMode(0,INPUT);	// Sets pin 0 as input
	// Didn't end up needing this because the detector sends out 0's if no motion is detected
	// pullUpDnControl (0, PUD_DOWN);	
	
	while(true)
	{
		
		cout << digitalRead(0) << endl;		// Reads pin 0
 
		//cout << "Motion Detected!!!" << endl;
		
		if(digitalRead(0)==1) //Checks for motion
		{
			system("raspistill -t 1000 -o security.jpg");
			system("echo \"Intruder Detected!!!\" | mutt -s \"\" -a ./security.jpg -- pipluspluspi@gmail.com");
			delay(2000);	//delays the read
		}
		while(digitalRead(0) == 1) //doesn't take another picture until motion is no longer detected.
		{
		}

	}
}