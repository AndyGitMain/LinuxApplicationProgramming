
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 1024

int main()
{
	int shmid;
	FILE *fp;
	char buf[BUF_SIZE];
	int skey = 5678;
	void *shared_memory = (void *)0;
	int *process_num;
	int local_num;


	/* create the shared memory */
	shmid = shmget((key_t)skey, sizeof(int), 0666 | IPC_CREAT);
	if (shmid == -1) {
		perror("failed to create a shared memory");
		exit(-1);
	}

	/* check ipc */
	printf("Key %x\n", skey);

	/* mapping a shared memory that is created by a process into memory area*/
	shared_memory = shmat(shmid, (const void *)0, 0);
	if (shared_memory == (void *)0) {
		perror("Failed to map the shared memory");
		exit(-1);
	}

	process_num = (int *)shared_memory;

	while (1) {
		local_num = 0;
		fp = popen("ps axh", "r");
		if (fp != NULL) {
			while (fgets(buf, 1024, fp)) {
				local_num++;
			}
		}
		*process_num = local_num;
		printf("process_num = %d\n", (int)*process_num);
		sleep(5);
		pclose(fp);
	}

	return 0;
}
