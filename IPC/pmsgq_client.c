#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>


int main()
{
	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 4;
	int value = 0;
	mqd_t mfd;

	mfd = mq_open("/my_mq", O_WRONLY, 0666, &attr);
	if (mfd == -1) {
		perror("Failed to open a message queue");
		exit(-1);
	}

	while (1) {
		if (mq_send(mfd, (char *)&value, attr.mq_msgsize, 1) == -1) {
			perror("Send Error");
			exit(-1);
		}
		sleep(1);
		value++;
	}

	return 0;
}
