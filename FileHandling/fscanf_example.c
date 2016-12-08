#include <stdio.h>
#include <stdlib.h>

/*
 * === data.txt ===
 * 123 456.789 forum
 * 1 123.456 falinux
 * 100 456.456 com
 * 
 */

#define BUF_SIZE 1024

int main()
{
	FILE *fp;
	int nInt;
	float nFloat;
	char str[BUF_SIZE] = {""};

	fp = fopen("./data.txt", "r");

	if (fp == NULL) {
		printf("Failed to open a file\n");
		exit(-1);
	}

	while (EOF != fscanf(fp, "%d %f %s", &nInt, &nFloat, str)) {
		printf("%d %f %s\n", nInt, nFloat, str);
	}

	fclose(fp);
	
	return 0;
}
