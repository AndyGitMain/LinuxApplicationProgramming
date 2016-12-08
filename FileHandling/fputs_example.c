#include <stdio.h>
#include <stdlib.h>

#define LEN    80

int main()
{
	char line[LEN + 1];
	FILE *fin;
	FILE *fout;

	fout = fopen("testfile.txt", "w");

	if (fout == (FILE *)NULL) {
		exit(-1);
	}
	
	fin = fdopen(0, "r");

	while ((fgets(line, LEN, fin) != NULL)) {
		fputs(line, fout);
	}

	fclose(fout);
	fclose(fin);

	return 0;
}
	
