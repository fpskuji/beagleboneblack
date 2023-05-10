#include <linux/can.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include "Defs.h"
#include "CanLib.h"
#include "TestLib.h"

void *Behavior1 (void *v)
{
	while (true) {
		if (ShutDown) {
			break;
		}
		
		SetForward();//F
		sleep(5);
		
		SetStop();//S
		sleep(3);
		
		TurnLeft();//G
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnBRight();//J
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnLeft();//G
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnBRight();//J
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		SetBackward();//B
		sleep(5);
		
		SetStop();//S
		sleep(3);
		
		TurnRight();//I
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnBLeft();//H
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnRight();//I
		sleep(3);
		
		SetStop();//S
		sleep(3);
		
		TurnBLeft();//H
		sleep(3);
		
		SetStop();//S
		sleep(3);
	}
}

// void *Behavior2 (void *v)
// {
	// while (true) { 
		// printf("Behavior2\n");
		// TurnLeft();
		// sleep(10);
		
		// TurnRight();
		// sleep(10);
	// }
// }

int main (void)
{
	pthread_t Task1;
	// pthread_t Task2;
	// pthread_t Task3;
	// pthread_t Task4;
	uint32_t rc;
	uint32_t i = 0;
	
	rc = system("config-pin p9.19 can");
	if (rc) {
		return rc;
	}

	rc = system("config-pin p9.20 can");
	if (rc) {
		return rc;
	}
	
	printf("Running Main Application\n");
	
	rc = CanInit("can0");
	if (rc) {
		return rc;
	}
	
	// ToggleHeadlightOn();
	// SetMotorSpeed();
	// SetForward();
	
	pthread_create(&Task1, NULL, Behavior1, NULL);
	// pthread_create(&Task2, NULL, Behavior2, NULL);
	//pthread_join(Task1, NULL);
	// pthread_join(Task2, NULL);
	
	while (true) {
		printf("ReceiveMessage\n");
		ReceiveMessage();
		// i++;
		
		// if (i > 50000000) {
			// Shutdown();
		// }
	}
	
	return ERROR_OK;
}

