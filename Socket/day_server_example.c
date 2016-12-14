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
#define DAYTIME_SERVER_PORT 1234
#define BACKLOG 10

int main()
{
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int server_fd, client_fd;
	char buffer[BUF_SIZE];
	time_t curTime;

	/* create socket for server */
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Failed to create socket");
		exit(-1);
	}
	
	/* set server address information */
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(DAYTIME_SERVER_PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	/* connect socket to the system */
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("Server : cannot bind local address\n");
		exit(-1);
	}
	
	/* listen for connections on a socket */
	if (listen(server_fd, BACKLOG) < 0) {
		perror("Server : cannot listen connect\n");
		exit(-1);
	}

	memset(buffer, 0x0, sizeof(buffer));
	printf("===== [PORT] : %d =====\n", DAYTIME_SERVER_PORT);
	
	while (1) {
		/* waiting connection reqeust from a client */
		printf("Server : waiting connection request.\n");
        client_fd = accept(server_fd, (struct sockaddr *)NULL, NULL);

		if (client_fd >= 0) {
			curTime = time(NULL);
            snprintf(buffer, BUF_SIZE, "%s\n", ctime(&curTime));
			write(client_fd, buffer, strlen(buffer));
			close(client_fd);
		}
	}
	

	return 0;
}
