#include <stdio.h>   // perror()
#include <stdlib.h>  // exit()
#include <string.h>  // strlen()
#include <fcntl.h>   // O_WRONLY

// Sender

#define FIFO_FILE   "./fifo"

int main()
{
	int fd;
	char *str = "forum.falinux.com";

	if (-1 == (fd = open(FIFO_FILE, O_WRONLY))) {
		perror("failed to open fifo");
		exit(-1);
	}

	write(fd, str, strlen(str));

	close(fd);
	
	return 0;
}
