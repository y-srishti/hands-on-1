/*
============================================================================
Name : 12.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to find out the opening mode of a file. Use fcntl.
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    printf("File opening mode: %s\n", (flags & O_RDWR) ? "O_RDWR" : (flags & O_RDONLY) ? "O_RDONLY" : "O_WRONLY");

    close(fd); 

    return 0;
}

