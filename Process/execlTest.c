
#include <stdio.h>
#include <unistd.h>

int main()
{
	int nValue;
	
	printf("Start~~~\n");
	scanf("%d", &nValue);
	execl("/bin/ps", "ps", "-e", NULL);
	printf("End~~~\n");

	return 0;
}
