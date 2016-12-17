/*
 * test redirection using dup2()
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STDIN  0
#define STDOUT 1
#define STDERR 2

int main()
{
	int fd;


	fd = open("./test.log", O_CREAT | O_WRONLY, 0x644);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}
	printf("fd = %d\n", fd);

	
	fd = dup2(fd, STDOUT);
	printf("Hellow world %d\n", fd);

	
	return 0;
}
