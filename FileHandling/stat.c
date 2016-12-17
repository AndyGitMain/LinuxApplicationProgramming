/*
 * struct stat {
 *     dev_t     st_dev;     // ID of device containing file
 *     ino_t     st_ino;     // inode number
 *     mode_t    st_mode;    // protection 
 *     nlink_t   st_nlink;   // number of hard links 
 *     uid_t     st_uid;     // user ID of owner 
 *     gid_t     st_gid;     // group ID of owner
 *     dev_t     st_rdev;    // device ID (if special file) 
 *     off_t     st_size;    // total size, in bytes 
 *     blksize_t st_blksize; // blocksize for filesystem I/O 
 *     blkcnt_t  st_blocks;  // number of 512B blocks allocated 
 *     time_t    st_atime;   // time of last access 
 *     time_t    st_mtime;   // time of last modification 
 *     time_t    st_ctime;   // time of last status change
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *filename;
	struct stat fileInfo;
	mode_t fileMode;
	
	if (argc != 2) {
		printf("Usage : ./filename file\n");
		exit(-1);
	}
	filename = argv[1];

	if (stat(filename, &fileInfo) == -1) {
		perror("Failed to get file information");
		exit(-1);
	}

	fileMode = fileInfo.st_mode;
	printf("==============================\n");
	printf("file name : %s\n", filename);
	printf("==============================\n");
	printf("file type : ");
	if (S_ISREG(fileMode)) {
		printf("A regular file\n");
	} else if (S_ISLNK(fileMode)) {
		printf("Symbolic link\n");
	} else if (S_ISDIR(fileMode)) {
		printf("Directory\n");
	} else if (S_ISCHR(fileMode)) {
		printf("Character device\n");
	} else if (S_ISBLK(fileMode)) {
		printf("Block device\n");
	} else if (S_ISFIFO(fileMode)) {
		printf("FIFO\n");
	} else if (S_ISSOCK(fileMode)) {
		printf("Socket\n");
	}

	printf("OWNER             : %d\n", fileInfo.st_uid);
	printf("GROUP             : %d\n", fileInfo.st_gid);
	printf("dev               : %d\n", fileInfo.st_dev);
	printf("inode             : %d\n", fileInfo.st_ino);
	printf("file size         : %d\n", fileInfo.st_size);
	printf("last access       : %d\n", fileInfo.st_atime);
	printf("last modification : %d\n", fileInfo.st_mtime);
	printf("hard link         : %d\n", fileInfo.st_nlink);


	return 0;
}





