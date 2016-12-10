/*
 * =====================================
 * Stream Client
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
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>

#define BUF_SIZE 128

int main(int argc, char *argv[])
{
	struct sockaddr_in server_addr;     /* my address information */
	struct sockaddr_in client_addr;  /* connector's address information */
	int server_fd, client_fd;       /* listen on server_fd, connection on client_fd */
	int sin_size;                   /* size of sockaddr_in */
	char *psServerIP;
	int nPort;
	char buffer[BUF_SIZE];
	ssize_t nMsgSize;
	
	/* check IP Address and PORT of the Server */
	if (argc != 3) {
		perror("Usage ./filename [IP Address of the Server] [PORT]\n");
		exit(-1);
	}
	psServerIP = argv[1];
	nPort = atoi(argv[2]);

	/* create socket for client */
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("");
		exit(-1);
	}

	/* set client address information */
	memset(&client_addr, 0x0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(nPort);
	client_addr.sin_addr.s_addr = inet_addr(psServerIP);

	/* connect to the server */
	if (connect(client_fd, (const struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
		perror("Client : cannot connect to the server\n");
		close(client_fd);
		exit(-1);
	}

	memset(buffer, 0x00, sizeof(buffer));

	while (1) {
	
		printf("Client ==> input string (exit): ");
		scanf("%s", buffer);
		printf("           size of psInput = %d\n", (int)sizeof(buffer));

		if (!strcmp(buffer, "exit")) {
			printf("Finished connection\n");
			break;
		}
		
		send(client_fd, buffer, sizeof(buffer), 0);

		nMsgSize = recv(client_fd, buffer, (size_t)sizeof(buffer), 0);
		printf("           received data from server : %s\n", buffer);
	}

	close(client_fd);
	
	return 0;
}
