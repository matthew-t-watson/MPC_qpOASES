
#include "networking.hpp"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>


#define BUFLEN 512  /* Max length of buffer */
#define PORT 8888

static const char odroidAddr[] = "143.167.51.120";


struct sockaddr_in si_odroid, si_myrio;
int s, i, recv_len;
unsigned int slen = sizeof(si_odroid);
char buf[BUFLEN];

int configureSockets()
{
	//create a UDP socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		printf("Failed to create socket, errno %i\n", errno);
		return errno;
	}

	// zero out the structure
	memset((char *) &si_odroid, 0, sizeof(si_odroid));

	si_odroid.sin_family = AF_INET;
	si_odroid.sin_port = htons(PORT);
	si_odroid.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET, odroidAddr, &(si_odroid.sin_addr));

	//bind socket to port
	if (bind(s, (struct sockaddr*) &si_odroid, sizeof(si_odroid)) == -1)
	{
		printf("Failed to bind socket to port, errno %i\n", errno);
		return errno;
	}
	return 0;
}

int getPacket()
{
	printf("Waiting for data...\n");

	//try to receive some data, this is a blocking call
	if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_myrio, &slen)) == -1)
	{
		printf("Error in recvfrom, errno %i\n", errno);
		return errno;
	}

	//print details of the client/peer and the data received
	printf("Received packet from %s:%d\n", inet_ntoa(si_myrio.sin_addr), ntohs(si_myrio.sin_port));
	printf("Data: %s\n" , buf);
}

int sendPacket()
{
	//now reply the client with the same data
	if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_myrio, slen) == -1)
	{
		printf("Error in sendto, errno %i\n", errno);
		return errno;
	}
}
