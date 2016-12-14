/*
 * =====================================
 * Day Server
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
#include <time.h>

#define BUF_SIZE 128

int main(int argc, char *argv[])
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int server_fd;
	int client_fd;
	char buffer[BUF_SIZE + 1];
	int nPort;
	char *psServerIP;
	int index = 0;
	int limit = BUF_SIZE;
	int in;
	
	if (argc != 3) {
		perror("Usage ./filename [IP Address][PORT]\n");
		exit(-1);
	}
	psServerIP = (char *)malloc(strlen(argv[1]));
	psServerIP = argv[1];
	nPort = atoi(argv[2]);
	
	/* create socket for client */
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Client : Failed to create socket\n");
		exit(-1);
	}
	
	/* set server address information */
	memset(&client_addr, 0x0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(nPort);
	client_addr.sin_addr.s_addr = inet_addr(psServerIP);
	
	/* connect to the server */
	if (connect(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
		perror("Client : cannot connect to the server\n");
		close(client_fd);
		exit(-1);
	}
	memset(buffer, 0x0, sizeof(buffer));
	
	while ((in = read(client_fd, &buffer[index], limit)) > 0) {
		index += in;
		limit -= in;
	}

	printf("\n%s\n", buffer);
	close(client_fd);
	
	return 0;
}
