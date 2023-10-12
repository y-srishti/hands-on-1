/*
============================================================================
Name : 9.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 15th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == -1) {
        perror("Error getting file information");
        return;
    }

    printf("File: %s\n", filename);
    printf("Inode: %lu\n", (unsigned long) file_stat.st_ino);
    printf("Hard links: %lu\n", (unsigned long) file_stat.st_nlink);

   
    printf("UID: %d\n", file_stat.st_uid);
    printf("GID: %d\n", file_stat.st_gid);

    printf("Size: %ld bytes\n", (long) file_stat.st_size);
    printf("Block size: %ld bytes\n", (long) file_stat.st_blksize);
    printf("Number of blocks: %ld\n", (long) file_stat.st_blocks);

    printf("Last access time: %s", ctime(&file_stat.st_atime));
    printf("Last modification time: %s", ctime(&file_stat.st_mtime));
    printf("Last change time: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    print_file_info(filename);

    return 0;
}

