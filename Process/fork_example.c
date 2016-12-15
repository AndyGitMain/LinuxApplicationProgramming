
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
#include <unistd.h>


int main()
{
	pid_t ret;
	int status, i;
	int role = -1;

	printf("Before fork()\n");
	ret = fork();
	printf("After fork()\n");
	
	if (ret > 0) {
		printf("Parent : This is the parent process (pid %d)\n", getpid());
		for (i = 0; i < 5; i++) {
			printf("Parent : At count %d\n", i);
			sleep(1);
		}
		ret = wait(&status);
		role = 0;
	} else if (ret == 0) {
		printf("Child : This is the child process (pid %d)\n", getpid());
		for (i = 0; i < 10; i++) {
			printf("Child : At count %d\n", i);
			sleep(1);
		}
		role = 1;
	} else {
		printf("Parent : Error trying to fork");
	}
	

	printf("%s : Exiting... \n", (role == 0) ? "Parent" : "Child");
	
	return 0;
}
