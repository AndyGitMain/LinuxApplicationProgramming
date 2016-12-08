#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;

	fp = fopen("file.txt", "w");

	if (fp == NULL) {
		printf("Failed to open a file\n");
		exit(-1);
	}

	fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2012);

	fclose(fp);
	
	return 0;
}
