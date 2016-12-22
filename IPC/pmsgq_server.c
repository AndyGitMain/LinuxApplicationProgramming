#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>


int main()
{
	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 4;
	int value;
	mqd_t mfd;

	mfd = mq_open("/my_mq", O_RDWR | O_CREAT, 0666, &attr);
	if (mfd == -1) {
		perror("Failed to open a message queue");
		exit(-1);
	}

	while (1) {
		if (mq_receive(mfd, (char *)&value, attr.mq_msgsize, NULL) == -1) {
			exit(-1);
		}
		printf("Read Data %d\n", value);
	}

	return 0;
}
