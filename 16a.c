/*
============================================================================
Name : 16a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to perform mandatory locking. Implement write lock.
Date: 20th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "locked_file.txt"; 

    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;   // Set a write (exclusive) lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;        // Start from the beginning of the file
    lock.l_len = 0;          // Lock the entire file
    lock.l_pid = getpid();   // Process ID
    
    printf("before critical section\n");
    fcntl(fd, F_SETLKW, &lock);

    printf("Write lock set on the file. Press Enter to release the lock...\n");
    getchar();

    lock.l_type = F_UNLCK;   // Release the lock

    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);

    return 0;
}

