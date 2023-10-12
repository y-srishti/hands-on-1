/*
============================================================================
Name : 17.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
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
       
        int ticket_count;
}db;

int main(){

        int fd;
        fd=open("ticket.txt", O_RDWR);

        struct flock lock;
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=0;
        lock.l_len= 0;
        lock.l_pid-getpid();

        printf("Before Entering into the critical section\n");
        fcntl(fd, F_SETLKW, &lock);
	printf("Entered critical section\n");
	read(fd, &db, sizeof(db));
	
        db.ticket_count++;

        printf("Ticket number: %d \n", db.ticket_count);
	printf("count incremented\n");

        lseek (fd,0, SEEK_SET);
        write (fd, &db, sizeof(db)); //updating db with new ticket number
        printf("To exit, press Enter: \n" ) ;
        getchar();
        lock.l_type=F_UNLCK;
        fcntl(fd ,F_SETLK, &lock);
        printf("Thank you\n") ;
}

