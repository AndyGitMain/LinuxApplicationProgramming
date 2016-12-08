#include <stdio.h>     // puts()
#include <stdlib.h>    // exit()
#include <fcntl.h>     // O_RDONLY
#include <unistd.h>

#define BUFF_SIZE 1024

int main()
{
	char buf[BUFF_SIZE] = {""};
	int fd;

	fd = open("./test.txt", O_RDONLY);
	
	if (0 > fd) {
		printf("Faild to open a file\n");
		exit(-1);
	}

	read(fd, buf, BUFF_SIZE);
	puts(buf);
		
	close(fd);
	
	return 0;
}
