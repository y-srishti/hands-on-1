/*
============================================================================
Name : 7.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to copy file1 into file2 
Date: 14th Aug, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("You are useless");
		return 1;
	}
	int fd_read = open(argv[1], O_RDONLY);
	int fd_write = open(argv[2], O_WRONLY|O_CREAT);
	if(fd_read==-1 || fd_write==-1)
		printf("Error opening files");
	while(1){
		char buff;
		int char_read = read(fd_read, &buff, 1); //reading and storing in buff and reading 1 byte at a time
		if(char_read==0) //reached EOF
			break;
		int char_written = write(fd_write, &buff, 1);
	}
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);

	if(fd_read_close==-1 || fd_write_close==-1)
		printf("Error closing files");
	return 0;
}
