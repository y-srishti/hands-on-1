/*
============================================================================
Name : 24.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create an orphan process.
Date: 1st Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
if (!fork()) {
printf("In child - Before orphan PPID = %d\n", getppid());sleep(1);
printf("In child - After orphan PPID = %d\n", getppid());
}
else {
printf("This is parent process %d\n", getpid());
exit(0);
}
}
