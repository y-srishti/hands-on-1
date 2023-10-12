/*
============================================================================
Name : 27d.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to execute ls -Rl by the system call execv
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    int excv= execv("/bin/ls", args);
    if (excv == -1) {
        printf("error in execv");
        return 1;
    }

    return 0;
}


