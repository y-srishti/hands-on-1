/*
============================================================================
Name : 1a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create a softlink using system call.
Date: 11th Aug, 2023.
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
                int j;
                int k;
        } db[3];

        for(i=0;i<3;i++){
                db[i].j=i+1;
                db[i].k=i+2;
        }

        fd=open("db_struct.txt",O_RDWR);
        write(fd,db, sizeof(db));
        close(fd);
}
