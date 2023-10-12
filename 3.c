/*
============================================================================
Name : 3.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 11th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd = open("myfile.txt", O_RDONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    } else {
        printf("File created successfully. File descriptor: %d\n", fd);
    }

    close(fd);

    return 0;
}

