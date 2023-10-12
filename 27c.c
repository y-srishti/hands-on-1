/*
============================================================================
Name : 27c.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to execute ls -Rl by the system call execle
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *envp[] = {NULL}; 
    int excle= execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp); 
    if (excle == -1) {
        printf("error in execle");
        return 1;
    }

    return 0;
}


