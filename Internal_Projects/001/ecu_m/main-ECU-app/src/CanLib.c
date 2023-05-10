/**
*   @file    CanLib.c
*   @implements CanLib.c_Artifact
*   @version 1.0.0
*   @file    CanLib.c
*   @implements Can interface using Socket CAN library
*
*   @brief   AUTOSAR Can - module interface
*   @details API implementation for CAN driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
#include <linux/can.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <net/if.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include "Defs.h"
#include "CanLib.h"

RET CanInit (const int8_t *CanIF)
{
	struct ifreq Ifr;
	struct sockaddr_can Addr;
	Addr.can_ifindex = ZERO;
	
	//Open a CAN raw socket 
	Socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (socket < ZERO) {
		printf("[%d]errno = %d\n", __LINE__, errno);
		return ERROR_INIT_SOCKET;
	}
	
	//Set interface request name and index
	//Need to call ioctl to get Ifr index
	strcpy(Ifr.ifr_name, CanIF);
	ioctl(Socket, SIOCGIFINDEX, &Ifr);
	if (ENODEV == errno) {
		printf("[%d]errno = %d\n", __LINE__, errno);
		return ERROR_INIT_IOCTL;
	}
	
	//Set address family number (AF_CAN)
	//Set CAN interface index
	Addr.can_family = AF_CAN;
	Addr.can_ifindex = Ifr.ifr_ifindex;
	
	
	if (bind(Socket, (struct sockaddr *)&Addr, sizeof(Addr))) {
		printf("[%d]errno = %d\n", __LINE__, errno);
		return ERROR_INIT_BIND;
	}
	
	return ERROR_OK;
}

RET CanRead (struct can_frame *Frame)
{
	uint8_t Size;
	struct timeval Tv;
	
	Size = read(Socket, Frame, sizeof(*Frame));
	ioctl(Socket, SIOCGSTAMP, &Tv);
	if (Size < ERROR_OK) {
		printf("[%d]errno = %d\n", __LINE__, errno);
		return ERROR_READ;
	}
	
	if (Size < sizeof(*Frame)) {
		return ERROR_READ_INCOMPLETE_FRAME;
	}
	
	return ERROR_OK;
}

RET CanWrite (const struct can_frame Frame)
{
	uint8_t Size;
	
	if (Frame.can_dlc < CAN_MIN_DLC && Frame.can_dlc > CAN_MAX_DLC) {
		return ERROR_WRITE_DLC_LENGTH;
	}
	Size = write(Socket, &Frame, sizeof(Frame));
	if (Size < ERROR_OK) {
		printf("[%d]errno = %d\n", __LINE__, errno);
		return ERROR_WRITE;
	}
	
	return ERROR_OK;
}