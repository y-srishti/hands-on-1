/*
============================================================================
Name : 18a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to perform Record locking. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

struct{
	int train_num;
	int ticket_count;
}db;

int main(){

	int fd, input;
	fd=open("record.txt", O_RDWR);
	printf("Select train number (1,2,3): \n");
       	scanf("%d", &input);
       
	struct flock lock;
       	lock.l_type=F_WRLCK;
       	lock.l_whence=SEEK_SET;
       	lock.l_start=(input-1)*sizeof(db);
       	lock.l_len= sizeof(db); 
	lock.l_pid-getpid();
       
	//reading value of ticket number 
	lseek(fd, (input-1)*sizeof(db), SEEK_SET); 
	read(fd, &db, sizeof(db));
       	printf("Before Entering into the critical section\n");
       
	fcntl(fd, F_SETLKW, &lock);
       	printf("Ticket number: %d \n", db.ticket_count); 
	db.ticket_count++; 
	lseek (fd,(input-1)*sizeof(db), SEEK_SET);
	write (fd, &db, sizeof(db)); //updating db with new ticket number
        printf("To Book Ticket, press Enter: \n" ) ;
       	getchar();
       	getchar();
       	lock.l_type=F_UNLCK; 
	fcntl(fd ,F_SETLK, &lock);
       	printf("Booked\n") ;
}
