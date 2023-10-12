/*
============================================================================
Name : 17_ticket.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file, store a ticket number and exit.
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
        int fd;
        struct {
               
                int ticket_count;
        } db;

        
        db.ticket_count=0;
        

        fd=open("ticket.txt",O_RDWR|O_CREAT,0644);
        write(fd,&db, sizeof(db));
        close(fd);
}
