/*
 * Signal catch using the signal function
 *
 */

#include <stdio.h>
#include <signal.h>


void sig_handler(int sig_num);

int main()
{
	int i = 0;

	signal(SIGINT, (void *)sig_handler); /* call sig_handler function */

	/*signal(SIGINT, SIG_IGN);*/	 /* ignore CTRL+C key */
	
	while (1) {
		printf("%d\n", i++);
		sleep(2);
	}
	
	return 0;
}


void sig_handler(int sig_num)
{
	printf("I received SIGINT(%d)\n", SIGINT);
	sleep(4);

}


