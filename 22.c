/*
============================================================================
Name : 22.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 1st Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int file = open("file.txt", O_RDWR| O_CREAT , 0644);
	if(file==-1){
		printf("ERROR IN FILE OPENING\n");
	}
	int id= fork();
	if(id==0) {
		const char *data = "Child has written this\n";
		int byte_written = write(file, data, strlen(data));
	}
	else{
		const char *data = "Parent has written this\n";
                int byte_written = write(file, data, strlen(data));
	}
        close(file);
        file = open("file.txt",O_RDWR, 0644);	
	char buff[2046];
	int f_read= read(file, buff,sizeof(buff));
	if (f_read==-1) {	
		printf("NOT READ\n");
	
	}
	
        int f_write=write(1, buff, f_read);
  	if (f_write==-1){
		printf("NOT WRITTEN\n");
	}
	
close(file);
return 0;
}
