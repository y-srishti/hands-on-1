/*
============================================================================
Name : 14.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *filepath = argv[1];
    struct stat file_stat;

    if (lstat(filepath, &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    if (S_ISREG(file_stat.st_mode)) {
        printf("%s is a regular file.\n", filepath);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("%s is a directory.\n", filepath);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("%s is a character special file.\n", filepath);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("%s is a block special file.\n", filepath);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", filepath);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("%s is a symbolic link.\n", filepath);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("%s is a socket.\n", filepath);
    } else {
        printf("%s is of unknown type.\n", filepath);
    }

    return 0;
}

