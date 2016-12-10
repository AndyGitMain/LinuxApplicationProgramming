/*
 * =====================================
 * Stream Server
 * =====================================
 *
 * struct sockaddr_in {
 *     sa_family_t    sin_family;   // address family
 *     in_port_t      sin_port;     // port number in network byte order
 *     struct in_addr sin_addr;     // internet address
 * };
 *
 * 
 * struct in_addr {
 *     uint32_t       s_addr;       // address in network byte order
 * };
 *
 * struct sockaddr {
 *     unsigned short sa_family;    // address family
 *     char           sa_data[14];  // 14 bytes of protocol address 
 *
 */


#include <stdio.h>
#include <stdlib.h>      /* exit() */
#include <string.h>      /* memset */
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>

#define MYPORT 3490
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	struct sockaddr_in server_addr;     /* my address information */
	struct sockaddr_in client_addr;     /* connector's address information */
	int server_fd, client_fd;           /* listen on server_fd, connection on client_fd */
	int sin_size;                       /* size of sockaddr_in */
	int nPort;
	char buffer[BUF_SIZE];
	size_t nLenClient;
	char sClientIP[20];
	ssize_t nMsgSize;
	
	/* check PORT number */
	if (argc != 2) {
		perror("Usage ./filename [PORT]\n");
		exit(-1);
	}
	nPort = atoi(argv[1]);

	/* create socket for server */
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Failed to create socket\n");
		exit(-1);
	}

	/* set server address information */
	memset(&server_addr, 0x0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(nPort);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	/* connect socket to the system */
	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("Server: cannot bind local address\n");
		exit(-1);
	}

	/* listen for connections on a socket */
	if (listen(server_fd, BACKLOG) < 0) {
		perror("Server: cannot listen connect\n");
		exit(-1);
	}

	memset(buffer, 0x00, sizeof(buffer));
	nLenClient = sizeof(client_addr);
	memset(sClientIP, 0x00, sizeof(sClientIP));
	
	printf("===== [PORT] : %d =====\n", nPort);

	while (1) {
		
		/* waiting connection request from a client */
		printf("Server : waiting connection request.\n");
		client_fd = accept(server_fd,
						   (struct sockaddr *)&client_addr,
						   (socklen_t *)&nLenClient);

		if (client_fd < 0) {
			perror("Server : failed to accept.\n");
			exit(-1);
		}

		/* convert IPv4 and IPv6 addresses from binary to text form */
		inet_ntop(AF_INET, &client_addr.sin_addr.s_addr,
				           sClientIP,
				           (socklen_t)sizeof(sClientIP));
		printf("Server ==> %s client connect.\n",sClientIP);

		nMsgSize = recv(client_fd, buffer, (size_t)sizeof(buffer), 0);

		printf("           received data from client : %s\n", buffer);		

		send(client_fd, buffer, nMsgSize, 0);
		
		printf("Server ==> sended data to client.\n");
	}

	close(server_fd);
	
	return 0;
}







