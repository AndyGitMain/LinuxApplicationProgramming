#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "inpfile.txt"

int main()
{
	FILE *fout;
	int i = 0;
	const char string[] = {"This\r\nis a test\r\nfile.\r\n\0"};

	fout = fopen(FILE_NAME, "w");

	if (fout == (FILE *)NULL) {
		printf("Failed to open file\n");
		exit(-1);
	}

	i = 0;
	while (string[i] != '\0') {
		fputc((int)string[i], fout);
		i++;
	}

	fclose(fout);
	
	return 0;
}
