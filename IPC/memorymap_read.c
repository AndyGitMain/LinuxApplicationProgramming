
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>



int main()
{
	int fd;
	int *maped;
	int i;
	int flag = PROT_WRITE | PROT_READ;

	fd = open("mymmap.mm", O_RDWR | O_CREAT, 0666);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}

	/* match the opened file to memory */
	maped = (int *)mmap(0, 4096, flag, MAP_SHARED, fd, 0);
	if ((unsigned int)maped == (unsigned int)-1 ) {
		perror("Failed to create a memory map");
		exit(-1);
	}

	while (1) {
		if (maped[i] == -1) {
			break;
		}
		printf("> %d\n", maped[i]);
		i++;
	}
	close(fd);
		
	return 0;
}
