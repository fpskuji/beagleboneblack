This folder contains the new implementation of the HSR04 Ultrasonic Sensor and its application in the airbag deployment. This is the edited version which contains the following changes:
EB Config Changes
	• Added FTM2 timer notification
	• Changed prescaler of FTM3 from 16 to 1 for easier calculation of timeout value
Code Changes
	• Front and Back Crash Detection - transferred from polling to interrupt based
	• Changed timeout values of GPT timers to 1ms
	• Changed stopping distance threshold to 10cm from 4cm
	• Simplified distance calculation. It is now reliant only on time (removed the multiplication process to convert time to distance)
	• Changed data type of Airbag_Flag to boolean
Tests Done
	• Do nothing for loop inside the infinite while loop
		○ Result: OK (does not affect distance measurement)
	• Printf statement inside infinite while loop
		○ Result: BAMBOOZLED (prevents interrupts from running)
	• CAN Simulation using Random Data for Switch Case
		○ Result: OK (does not affect distance measurement)
Documentation
	• Waiting for approval of code to reflect changes
Changes in EB Config are already reflected

Project Folder: Contains the EB Tresos configuration and its corresponding Tresos studio workspace.
IP_HCSR04 Folder: Contains the IAR wrokspace and source code files for the HCSR04 implementation ang airbag deployment logic.
