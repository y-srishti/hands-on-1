/*
============================================================================
Name : 5.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 13th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    const char *fileNames[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    for (int i = 0; i < 5; i++) {
        int fd = open(fileNames[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }

        printf("Created %s\n", fileNames[i]);

        close(fd);
    }
    while(1){}

    return 0;
}

