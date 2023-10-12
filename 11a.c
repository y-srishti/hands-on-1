/*
============================================================================
Name : 11a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not (use dup).
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write initial content using the original file descriptor
    const char *data = "Original content\n";
    int bytesWritten = write(fd, data, strlen(data));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // Duplicate the file descriptor
    int new_fd = dup(fd);
    if (new_fd == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Append additional content using the duplicated file descriptor
    const char *additionalData = "Additional content\n";
    int additionalBytesWritten = write(new_fd, additionalData, strlen(additionalData));
    if (additionalBytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        close(new_fd);
        return 1;
    }

    printf("File updated successfully.\n");

    close(fd);      // Close the original file descriptor
    close(new_fd);  // Close the duplicated file descriptor

    return 0;
}

