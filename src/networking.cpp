
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
inline void printMatrix(const char* name, double* data, uint32_t rowWidth, uint32_t colWidth);
inline void swapDoubleWords(double* data, size_t numel);


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

	/* Swap double word order */
	swapDoubleWords(buf.x, NX);
	swapDoubleWords(buf.r, NX*NR);

	printf("Received data with id %i, initial state\n", buf.id);

	printMatrix("x", buf.x, NX, 1);
	printMatrix("r", buf.r, NX, NR);


	return 0;
}

int sendPacket(MPCPacketResult_t& data)
{
	printf("Sending packet id %i with\n", data.id);
	printMatrix("c", data.c, NU, NC);
	printMatrix("cinf", data.cinf, NU, 1);
	printMatrix("s", data.s, NS, 1);
	printMatrix("u", data.u, NU, 1);

	/* Swap double words back */
	swapDoubleWords(data.c, data.c_len);
	swapDoubleWords(data.cinf, data.cinf_len);
	swapDoubleWords(data.s, data.s_len);
	swapDoubleWords(data.u, data.u_len);

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

inline void printMatrix(const char* name, double* data, uint32_t rowWidth, uint32_t colWidth)
{
	printf("%s = [", name);

	for (int i = 0; i < rowWidth; i++)
	{
		for (int j = 0; j < colWidth; j++)
		{
			printf("\t%e", data[i * rowWidth + j]);
		}
		printf("\n");
	}
	printf("]\n");
}

inline void swapDoubleWords(double* data, size_t numel)
{
	for (int i = 0; i < numel; i++)
	{
		((uint64_t*)data)[i] = ((((uint64_t*)data)[i]<<32) | (((uint64_t*)data)[i]>>32));
	}
}

