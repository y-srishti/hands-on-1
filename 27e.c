/*
============================================================================
Name : 27e.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to execute ls -Rl by the system call execvp
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = { "ls", "-Rl", NULL};
    int excvp= execvp("ls", args);
    if (excvp == -1) {
        printf("error in execvp");
        return 1;
    }

    return 0;
}


