#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MYFILE "missing.txt"

int main()
{
	FILE *fin;

	/* Try to open the file */
	fin = fopen(MYFILE, "r");
    
	/* Check for failure to open */
	if (fin == (FILE *)NULL) {
		/* Emit an error message and exit */
		printf("%s : %s\n", MYFILE, strerror(errno));
		exit(-1);
	}

	/* All was well, close the file */
	fclose(fin);
	
	return 0;
}
