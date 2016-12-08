#include <stdio.h>
#include <stdlib.h>

#define LEN    80

int main()
{
	char line[LEN + 1];
	FILE *fin;

	fin = fopen("testfile.txt", "r");

	if (fin == (FILE *)NULL) {
		exit(-1);
	}

	while ((fgets(line, LEN, fin) != NULL)) {
		printf("%s", line);
	}

	fclose(fin);

	return 0;
}
	
