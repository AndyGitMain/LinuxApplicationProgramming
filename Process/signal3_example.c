/*
 * usage : ./filename [pid] [sigNum]
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>



int main(int argc, char *argv[])
{
	int pid;
	int sigNum;

	if (argc != 3) {
		printf("usage %s [pid] [sigNum]\n", argv[0]);
		exit(-1);
	}

	pid = atoi(argv[1]);
	sigNum = atoi(argv[2]);

	if (kill(pid, sigNum) != 0) {
		perror("Sending signal error");
		exit(-1);
	}
	
	return 0;
}
