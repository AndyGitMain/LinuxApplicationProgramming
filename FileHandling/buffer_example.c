
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int i = 1;

	while (1) {
		printf("%d", i);
		fflush(stdout);
		usleep(100000);
	}
	
	return 0;
}
