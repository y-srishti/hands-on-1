/*
============================================================================
Name : 1a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create a softlink using system call.
Date: 11th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *targetPath = "target.txt";   
    const char *linkPath = "softlink";   

    if (access(targetPath, F_OK) != 0) {
        int targetFile = open(targetPath, O_CREAT | O_WRONLY, 0644);
        if (targetFile == -1) {
            perror("Error creating target file");
            return 1;
        }
        close(targetFile);
    }

    int result = symlink(targetPath, linkPath);
    if (result == -1) {
        perror("Error creating symbolic link");
        return 1;
    }

    printf("Symbolic link created successfully.\n");

    return 0;
}

