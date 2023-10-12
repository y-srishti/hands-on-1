/*
============================================================================
Name : 20.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Get the current nice value (priority) of the running program
    int nice_val = nice(0);
    if (nice_val == -1) {
        perror("nice");
        return 1;
    }

    printf("Current priority of this program: %d\n", nice_val);

    // Modify the priority (e.g., increase by 5)
    int new_nice_val = nice_val + 5;
    if (nice(new_nice_val) == -1) {
        perror("nice");
        return 1;
    }

    printf("New priority of this program: %d\n", nice(new_nice_val));

    return 0;
}


