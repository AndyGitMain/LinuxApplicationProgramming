#include <stdio.h>
#include <stdlib.h>  // exit()
#include <unistd.h>  // pipe()
#include <string.h>  // strlen()

// typedef int __kernel_pid_t;
// typedef __kernel_pid_t pid_t;

#define BUF_SIZE 1024

int main()
{
	int pipes_parent[2];
	int pipes_child[2];
	char buf[BUF_SIZE];
	int counter = 0;
	pid_t pid;

	if (-1 == pipe(pipes_parent)) {
		perror("Failed to create pipe.\n");
		exit(-1);
	}

	if (-1 == pipe(pipes_child)) {
		perror("Failed to create pipe.\n");
		exit(-1);
	}

	// create a new process by duplicating the calling process
	pid = fork();

	if (-1 == pid ) {
		perror("Failed to create a child process.\n");
		exit(-1);
	}
	
	switch (pid) {
	case 0:
		while (1) {
		    sprintf(buf, "child message : %d", counter++);
			write(pipes_child[1], buf, strlen(buf));
			memset(buf, 0, BUF_SIZE);
			read(pipes_parent[0], buf, BUF_SIZE);
			printf("child process : %s\n", buf);
			sleep(1);
		}
		//		break;
	default:
		while (1) {
		    sprintf(buf, "parent message : %d", counter--);
			write(pipes_parent[1], buf, strlen(buf));
			memset(buf, 0, BUF_SIZE);
			read(pipes_child[0], buf, BUF_SIZE);
			printf("parent process : %s\n", buf);
			sleep(1);
		}
	}
	

	return 0;
}
