/*
============================================================================
Name : 10.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 15th Aug, 2023.
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

    const char *data1 = "0123456789";
    ssize_t bytesWritten1 = write(fd, data1, 10);
    if (bytesWritten1 == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    off_t newOffset = lseek(fd, 10, SEEK_CUR);
    if (newOffset == -1) {
        perror("Error moving file pointer");
        close(fd);
        return 1;
    }

    const char *data2 = "abcdefghij";
    ssize_t bytesWritten2 = write(fd, data2, 10);
    if (bytesWritten2 == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("File pointer offset after lseek: %ld\n", (long)newOffset);

    close(fd);
    system("od -c file.txt");
    return 0;
}

