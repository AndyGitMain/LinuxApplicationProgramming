/*
 * #include <signal.h>
 *
 * sighadler_t signal(int signum, sighandler_t handler);
 *         - sets the disposition of the signal signum to handler,
 *           which is either SIG_IGN, SIG_DFL, or the address
 *           of a programmer-defined function
 *
 * int pause(void);
 *         - 
 *
 */

#include <stdio.h>
#include <signal.h>



int main()
{
	int i = 0;

	while (1) {
		printf("%d\n", i++);
		sleep(1);
	}
	
	return 0;
}
