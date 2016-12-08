#include <stdio.h>     // printf()
#include <string.h>    // strlen()
#include <fcntl.h>     // open(), O_WRONLY, O_CREAT, O_EXCL
#include <sys/stat.h>  // S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH
#include <unistd.h>    // read(), write(), close(), 

int main()
{
	char *temp = "forum.falinux.com\n";
	int fd;

	if (0 < (fd = open("./test.txt", O_WRONLY | O_CREAT | O_EXCL,
					   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)))	{
		write(fd, temp, strlen(temp));
		close(fd);
	} else {
		printf("Failed to open a file");
	}

	return 0;
}
