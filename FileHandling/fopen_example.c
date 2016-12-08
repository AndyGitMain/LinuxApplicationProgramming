#include <stdio.h>    // fopen()
#include <stdlib.h>   // malloc(), exit()

int main()
{
	FILE *fp;
	char *str;
	int buf_size = 1024;
	
	fp = fopen("./test.txt", "r");

	if (fp == NULL) {
		printf("Failed to open a file\n");
		exit(-1);
	}

	str = malloc(buf_size + 5);

	while (fgets(str, buf_size, fp) != NULL) {
		printf("%s", str);
	}

	fclose(fp);
	free(str);
	
	return 0;
}
