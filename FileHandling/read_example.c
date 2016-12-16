#include <stdio.h>     // puts()
#include <stdlib.h>    // exit()
#include <fcntl.h>     // O_RDONLY
#include <unistd.h>

#define BUFF_SIZE 1024

int main()
{
	int fd;
	int buf;
	int nRead = 0;

	fd = open("./openData.txt", O_RDONLY);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}

	while ((nRead = read(fd, (void *)&buf, sizeof(int))) > 0) {
		printf("Read data : %d\n", buf);
	}

	close(fd);
	return 0;
	
	
	/*
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
	*/
}
