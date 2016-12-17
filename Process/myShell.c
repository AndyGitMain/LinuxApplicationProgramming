#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUF_SIZE 1024

#define chop(str) (str[strlen(str) - 1] = 0x00)

int main()
{
	char buf[BUF_SIZE];
	int pid;
	
	printf("This is my shell\n");

	while (1) {
		/* waiting user input */
		printf("# ");
		fgets(buf, BUF_SIZE - 1, stdin);
		chop(buf);

		/* check quit */
		if (strncmp(buf, "quit", 4) == 0) {
			printf("Bye Bye ~~~ \n");
			exit(0);
		}
		
		if (access(buf, X_OK) == 0) {			/* available command */
			pid = fork();
			/* parent */
			if (pid > 0) {
				printf("======Start to wait on the parent process\n");
				int status;
				waitpid(pid, &status, WUNTRACED);
				printf("======Finished to wait stopping child process\n");
			/* child */
			} else if (pid == 0) {
				if (execl(buf, buf, NULL) == -1) {
					fprintf(stderr, "Command Exec Error\n\n");
				}
				exit(0);
			} else {
				fprintf(stderr, "Fork Error\n\n");
			}
		} else {		  		                /* unavailable command */
			fprintf(stderr, "Command Not Found\n\n");
		}
	}

	return 0;
}
