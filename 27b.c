/*
============================================================================
Name : 27b.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to execute ls -Rl by the system call execlp
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int exclp= execlp("ls", "ls", "-Rl", (char *)NULL);
    if (exclp == -1) {
        printf("error in execlp");
        return 1;
    }

    return 0;
}


