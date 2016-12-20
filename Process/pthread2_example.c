

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void *t_function(void *data)
{
	char c[100000];
	int num = *((int *)data);

	printf("Thread start\n");
	sleep(5);
	printf("Thread end\n");

}



int main()
{
	pthread_t p_thread;
	int thr_id;
	int status;
	int a = 100;

	printf("Before Thread\n");
	thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
	if (thr_id != 0) {
		perror("Failed to create a thread 1");
		exit(-1);
	}
	printf("p_thread = %d\n", (int)p_thread);

	pthread_detach(p_thread);
	pause();
	
	return 0;
}



