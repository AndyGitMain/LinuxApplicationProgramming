
/*
 * 
 * 
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getpid();
 *        - returns the process ID of the calling process.
 * pid_t getppid()
 *        - returns the process ID of the parent of the calling process.
 * pid_t getgid()
 *        - returns the real group ID of the calling process.
 * pid_t getuid()
 *        - returns the real user ID of the calling process.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	pid_t myPid;
	pid_t myParentPid;
	pid_t myGid;
	pid_t myUid;

	myPid = getpid();
	myParentPid = getppid();
	myGid = getgid();
	myUid = getuid();
	
	printf("my process id is %d\n", myPid);
	printf("my parent's process id is %d\n", myParentPid);
	printf("my group id is %d\n", myGid);
	printf("my user id is %d\n", myUid);
	
	return 0;
}
