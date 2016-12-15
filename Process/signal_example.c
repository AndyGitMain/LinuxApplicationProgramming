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


void catch_ctlc(int sig_num);

int main()
{
	signal(SIGINT, catch_ctlc);

	printf("Go ahead, make my day.\n");

	pause();
	
	return 0;
}



void catch_ctlc(int sig_num)
{
	printf("Caught Control-C\n");
	fflush(stdout);

	return;
}
