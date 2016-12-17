
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define STDIN  0
#define STDOUT 1
#define STDERR 2

#define ERRMSG "Devide not zero\n"

int main()
{
	int fd;
	int a;
	int b;
	char buf[80];

	fd = open("./myAddrBook.txt", O_RDONLY);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}
	printf("fd = %d\n", fd);
	close(fd);

	
	read(STDIN, (void *)buf, sizeof(buf));
	a = atoi(buf);

	read(STDIN, (void *)buf, sizeof(buf));
	b = atoi(buf);

	if (b == 0) {
		printf("Fail\n");
		write(STDERR, (void *)buf, strlen(ERRMSG));
		return 1;
	}

	sprintf(buf, "%d / %d = %d\n", a, b, (int)(a / b));
	write(STDOUT, buf, strlen(buf));
	
	return 0;
}
