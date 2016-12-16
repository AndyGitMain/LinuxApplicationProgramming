
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd;
	int i;
	int wData = 0;
	int wSize = 0;
	

	fd = open("./openData.txt", O_CREAT | O_WRONLY);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}

	for (i = 0; i < 10; i++) {
		wData = i * 2;
		wSize = write(fd, (void *)&wData, sizeof(int));
		printf("Write %d (%d byte)\n", wData, wSize);
	}

	close(fd);
	return 0;
}
