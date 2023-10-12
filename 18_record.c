/*
============================================================================
Name : 18_record.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create three records in a file. 
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int i, fd;
	struct {
		int train_num;
		int ticket_count;
	} db[3];

	for(i=0;i<3;i++){
		db[i].train_num=i+1;
		db[i].ticket_count=0;
	}

	fd=open("record.txt",O_RDWR|O_CREAT,0644);
	write(fd,db, sizeof(db));
	close(fd);
}
