
/*
 *
 * #include <unistd.h>
 *
 * pid_t fork(void);
 *         - create a new process by duplicating the calling process
 *
 * return value : (PID) of the child process to a parent process
 *                (0) to a child process
 *                (-1) failed to create a child process
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 *
 * pid_t wait(int *status);
 *         - suspends execution of the calling process until one of
 *           its children terminates.
 *         - synchronizing process
 * pid_t waitpid(pid_t pid, int *status, int options);
 *         - suspends execution of the calling process until a child
 *           specified by pid argument has changed state.
 *         - ex) waitpid(-1, &status, 0);
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	pid_t pid;
	int i = 1000;
	
	printf("Before fork()\n");
	pid = fork();
	printf("After fork()\n");

	/* Parent */
	if (pid > 0) {
		printf("Parent : my child pid is %d\n", pid);
		sleep(5);
		printf("Parent : is killed\n");
		exit(0);
    /* Child */
	} else if (pid == 0) {
		printf("Child : my pid is %d\n", getpid());
		close(0);
		close(1);
		close(2);
		setsid();
		while (1) {
			printf("-->%d\n", i);
			i++;
			sleep(1);
		}
	} else {
		perror("Parent : Error trying to fork");
		exit(0);
	}
	

	return 0;
}
