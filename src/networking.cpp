
#include "networking.hpp"
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>


#define PORT 8888

int getInterfaceIP(char* ip, const char* interface);
void printMatrix(const char* name, double data[], uint32_t nRow, uint32_t nCol);


struct sockaddr_in si_odroid, si_myrio;
int s, i, recv_len;
unsigned int slen = sizeof(si_odroid);

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

	char eth0Addr[20];
	if (getInterfaceIP(eth0Addr,"eth0") > 0)
	{
		printf("Failed to obtain eth0 IP\n");
		return 1;
	}

	si_odroid.sin_family = AF_INET;
	si_odroid.sin_port = htons(PORT);
	si_odroid.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_pton(AF_INET, eth0Addr, &(si_odroid.sin_addr));


	/* bind socket to port */
	if (bind(s, (struct sockaddr*) &si_odroid, sizeof(si_odroid)) == -1)
	{
		printf("Failed to bind socket to port, errno %i\n", errno);
		return errno;
	}
	return 0;
}

int getPacket(MPCPacketParams_t& buf)
{
	/* Blocking receive */
	if ((recv_len = recvfrom(s, &buf, sizeof(buf), 0, (struct sockaddr *) &si_myrio, &slen)) == -1)
	{
		printf("Error in recvfrom, errno %i\n", errno);
		return errno;
	}

#ifdef VERBOSE
	printf("Received data with id %i, r_len %i,\n", buf.id, buf.r_len);
	printMatrix("x", buf.x, 1, NX);
	printMatrix("r", buf.r, NR, 3);
#endif


	return 0;
}

int sendPacket(MPCPacketResult_t& data)
{
#ifdef VERBOSE
	printf("Sending packet with id = %i, nWSR = %i, exitFlag = %i,\n", data.id, data.nWSR, data.exitFlag);
	printMatrix("c", data.c, NC, NU);
	printMatrix("cinf", data.cinf, 1, NU);
	printMatrix("s", data.s, 1, NS);
	printMatrix("u", data.u, 1, NU);
#endif

	/* Send packet */
	if (sendto(s, &data, sizeof(data), 0, (struct sockaddr*) &si_myrio, slen) == -1)
	{
		printf("Error in sendto, errno %i\n", errno);
		return errno;
	}
	//printf("Sent %u bytes", sizeof(data));
	return 0;
}

int sendPacket(MPCPacketResultReduced_t& data)
{
#ifdef VERBOSE
	printf("Sending packet with id = %i, nWSR = %i, exitFlag = %i,\n", data.id, data.nWSR, data.exitFlag);
	printMatrix("u", data.u, 1, NU);
#endif

	/* Send packet */
	if (sendto(s, &data, sizeof(data), 0, (struct sockaddr*) &si_myrio, slen) == -1)
	{
		printf("Error in sendto, errno %i\n", errno);
		return errno;
	}
	//printf("Sent %u bytes", sizeof(data));
	return 0;
}

int getInterfaceIP(char* ip, const char* interface)
{
	struct ifaddrs *ifaddr, *ifa;
	int family, s, n;
	*ip = 0;

	if (getifaddrs(&ifaddr) == -1)
	{
		printf("Error in getifaddrs, errno %i\n", errno);
		return errno;
	}

	for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++)
	{
		if (ifa->ifa_addr == NULL)
			continue;

		family = ifa->ifa_addr->sa_family;

		if (strcmp(ifa->ifa_name, interface) == 0
				&& ifa->ifa_addr->sa_family == AF_INET)
		{
			s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), ip,
					NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
			if (s != 0)
			{
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				return 1;
			}
			break;
		}
	}
	if (strlen(ip) == 0)
	{
		printf("Failed to determine eth0 IP\n");
		return 1;
	}

	freeifaddrs(ifaddr);
	return 0;
}

void printMatrix(const char* name, double data[], uint32_t nRow, uint32_t nCol)
{
	printf("%s = \n[", name);

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			printf("\t%.10e", data[i * nCol + j]);
		}
		printf("\n");
	}
	printf("]\n");
}


