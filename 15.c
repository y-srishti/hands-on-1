/*
============================================================================
Name : 15.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to display the environmental variable of the user (use environ).
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    char **env = environ;

    printf("Environmental Variables:\n");

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

