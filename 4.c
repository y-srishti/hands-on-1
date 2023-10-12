/*
============================================================================
Name : 4.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 13th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    int fd = open("target.txt", O_RDONLY | O_EXCL | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
    } else {
        printf("File opened with file descriptor: %d\n",fd);
        close(fd);
    }


    return 0;
}

