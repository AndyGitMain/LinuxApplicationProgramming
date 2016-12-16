
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


struct userInfo {
	char name[28];
	int age;
	int sex;
	char hobby[28];
};

void makeUserInfo(struct userInfo *uInfo, char *name, int age, int sex, char *hobby);

int main()
{
	struct userInfo myAddrBook;
	int fd;

	fd = open("./myAddrBook.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}

	makeUserInfo(&myAddrBook, "Andy", 42, 0, "System Programmer");
	write(fd, (void *)&myAddrBook, sizeof(struct userInfo));
	
	makeUserInfo(&myAddrBook, "Suzy", 42, 1, "Web Programmer");
	write(fd, (void *)&myAddrBook, sizeof(struct userInfo));
	
	makeUserInfo(&myAddrBook, "Yun", 42, 1, "QA");
	write(fd, (void *)&myAddrBook, sizeof(struct userInfo));

	close(fd);

	return 0;
}


void makeUserInfo(struct userInfo *uInfo, char *name, int age, int sex, char *hobby)
{
	memset((void *)uInfo, 0x0, sizeof(struct userInfo));
	strcpy(uInfo->name, name);
	uInfo->age = age;
	uInfo->sex = sex;
	strcpy(uInfo->hobby, hobby);	
}
