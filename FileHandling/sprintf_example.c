#include <stdio.h>

#define BUF_SIZE 1024

int main()
{
	char buf[BUF_SIZE] = {""};
	int ret;

	ret = sprintf(buf, "%d %x %s", 123, 123, "forum.falinux.com");
	printf("ret = %d, buf = %s\n", ret, buf);
	
	return 0;
}
