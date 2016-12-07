#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *fin;

	fin = fopen("inpfile.txt", "r");

	if (fin == (FILE *)0)
		exit(-1);

	do {
		c = fgetc(fin);
		if (c != EOF) {
			printf("%c", (char)c);
		}
	} while (c != EOF);

	fclose(fin);		
	
	return 0;
}
