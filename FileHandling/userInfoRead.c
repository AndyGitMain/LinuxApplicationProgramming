

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define FILENAME "./myAddrBook.txt"

struct userInfo {
	char name[28];
	int age;
	int sex;
	char hobby[28];
};

int main()
{
	struct userInfo myAddrBook;
	int fd;
	
	fd = open(FILENAME, O_RDONLY);
	if (fd < 0) {
		perror("Failed to open a file");
		exit(-1);
	}

	printf("==============================\n");
	printf("User Info\n");
	printf("==============================\n");
	while (read(fd, (void *)&myAddrBook, sizeof(struct userInfo)) > 0) {
		printf("name  : %s\n", myAddrBook.name);
		printf("age   : %d\n", myAddrBook.age);
		printf("sex   : %d\n", myAddrBook.sex);
		printf("hobby : %s\n", myAddrBook.hobby);
		printf("==============================\n");
	}



	close(fd);

	return 0;
}
