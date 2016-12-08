#include <stdio.h>   // perror()
#include <stdlib.h>  // exit()
#include <fcntl.h>   // O_RDWR
#include <string.h>  // memset()

// Create and Receiver

#define FIFO_FILE  "./fifo"
#define BUF_SIZE   1024


int main()
{
	int counter = 0;
	int fd;
	char buf[BUF_SIZE];

	if (-1 == mkfifo(FIFO_FILE, 0666)) {
		perror("failed to create mkfifo");
		exit(-1);
	}

	if (-1 == (fd = open(FIFO_FILE, O_RDWR))) {
		perror("failed to open fifo");
		exit(-1);
	}
	
	while (1) {
		memset(buf, 0, BUF_SIZE);
		read(fd, buf, BUF_SIZE);
		printf("%d : %s\n", counter++, buf);
	}

	close(fd);
		
	return 0;
}
