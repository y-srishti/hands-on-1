/*
============================================================================
Name : 27a.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to execute ls -Rl by the system call execl
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int excl= execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    if (excl == -1) {
        printf("error in execl");
        return 1;
    }

    return 0; 
}

