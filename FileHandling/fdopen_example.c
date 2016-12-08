#include <stdio.h>    // fdopen()
#include <stdlib.h>   // exit()
#include <fcntl.h>    // O_RDONLY


#define BUF_SIZE 1024

int file_size(int fd)
{
	FILE *fp;
	int sz_file;

	fp = fdopen(fd, "r");

	if (fp == NULL) {
		printf("Failed to open from a file descriptor\n");
		return sz_file = -1;
	}

	fseek(fp, 0L, SEEK_END); // move the pointer to the the end
	sz_file = ftell(fp);     // return the current position
	lseek(fd, 0, SEEK_SET);  // move the pointer to the first

	fclose(fp);

	return sz_file;

}


int main()
{
	int fd;
	char buf[BUF_SIZE] = {""};
	

	fd = open("./test.txt", O_RDONLY,
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // 0644

	if (0 > fd) {
		printf("Failed to open a file\n");
		exit(-1);
	}

	printf("file size = %d\n", file_size(dup(fd)));

	while (0 < read(fd, buf, BUF_SIZE)) {
		printf("%s\n", buf);
	}
	
	return 0;
}
