/*
============================================================================
Name : 8.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 14th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	if(argc!=2){
		printf("wrong wrong");
		return 0;
	}

	int fd_read = open(argv[1], O_RDONLY);
	if(fd_read==-1){
		printf("Error opening file");
	}

	while(1){
		char buf[1024];
		char one;
		int j=0;
		int char_read;
		while(buf[j-1]!='\n' && char_read!=0){
			char_read = read(fd_read, &one, 1);
			buf[j]=one;
			j++;
		}

		int char_write = write(2, &buf, j);
                sleep(1);
		if(char_read==0)
			break;
	}

	int fd_close=close(fd_read);
        if(fd_close==-1){
		printf("Error closing file");
	}
	return 0;
}
