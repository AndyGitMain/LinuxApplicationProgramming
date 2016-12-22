/* Structure used for argument to `semop' to describe operations.
 *
 * struct sembuf
 * {
 *   unsigned short int sem_num;	// semaphore number
 *   short int sem_op;		        // semaphore operation
 *   short int sem_flg;		        // operation flag
 * };
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define MAX_THREAD 2
#define SEM_KEY    2345

int count = 0;

void *myThreadFunc(void *data);

struct sembuf mysem_open = {0, -1, SEM_UNDO};
struct sembuf mysem_close = {0, 1, SEM_UNDO};

union snum
{
	int val;
};

static int semid;

int main()
{
	int thr_id;
	int status;
	int i;
	union snum s_union;
	pthread_t pt[MAX_THREAD];

	semid = semget(SEM_KEY, 1, 0600 | IPC_CREAT);
	if (semid == -1) {
		perror("Failed to create a semaphore");
		exit(-1);
	}

	s_union.val = 1;
	if (semctl(semid, 0, SETVAL, s_union) == -1) {
		perror("Failed to create a semaphore control operations");
		exit(-1);
	}

	for (i = 0; i < MAX_THREAD; i++) {
		thr_id = pthread_create(&pt[i], NULL, myThreadFunc, (void *)&i);
		if (thr_id < 0) {
			perror("Failed to create a thread");
			exit(-1);
		}
		sleep(1);
	}

	for (i = 0; i < MAX_THREAD; i++) {
		pthread_join(pt[i], NULL);
	}
	
	return 0;
}

void *myThreadFunc(void *data)
{
	int thread_num = *(int *)data;
	int lnum;
	printf("Thread Create %d\n", thread_num);

	while (1) {
		semop(semid, &mysem_open, 1);
		lnum = count;
		sleep(1);
		lnum = lnum + 1;
		count = lnum;
		printf("[%d] count : %d\n", thread_num, count);
		semop(semid, &mysem_close, 1);
	}
}

