

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>




int main()
{
	int shmid;
	int skey = 5678;
	int *shared_memory;

	/* create a shared memory */
	shmid = shmget((key_t)skey, sizeof(int), 0666);
	if (shmid == -1) {
		perror("Failed to create a shared memory");
		exit(-1);
	}

	/* mapping a shared memory */
	shared_memory = shmat(shmid, (const void *)0, 0);
	if (shared_memory == (void *)0) {
		perror("Failed to map a shared memory");
		exit(-1);
	}

	printf("shm id : %d\n", shmid);
	while (1) {
		int num = *shared_memory;
		printf("Process number : %d\n", num);
		sleep(1);
	}
	
	return 0;
}
