#include <stdio.h>
#include <fcntl.h>   // open()
#include <string.h>  // strlen()

#define BUF_SIZE 1024

int main()
{
	int fd_wr;
	int fd_rd;
	char buf[BUF_SIZE];
	char *str = "forum.linux.com";

	fd_wr = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd_rd = dup(fd_wr);

	write(fd_wr, str, strlen(str));

	close(fd_wr);

	lseek(fd_rd, 0, SEEK_SET);
	memset(buf, '\0', BUF_SIZE);
	read(fd_rd, buf, BUF_SIZE);

	printf("%s\n", buf);

	close(fd_rd);
	
	return 0;
}
