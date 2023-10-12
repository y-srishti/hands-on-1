/*
============================================================================
Name : 11c.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not (use fcntl).
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char *data = "Original content\n";
    ssize_t bytesWritten = write(fd, data, strlen(data));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    int new_fd = fcntl(fd, F_DUPFD, 100); // Using an arbitrary new file descriptor number (e.g., 100)
    if (new_fd == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    const char *additionalData = "Additional content\n";
    ssize_t additionalBytesWritten = write(new_fd, additionalData, strlen(additionalData));
    if (additionalBytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        close(new_fd);
        return 1;
    }

    printf("File updated successfully.\n");

    close(fd);     
    close(new_fd);  

    return 0;
}

