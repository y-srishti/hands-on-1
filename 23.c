/*
============================================================================
Name : 23.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create a Zombie state of the running program.
Date: 1st Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
if (!fork()) {
printf("In child - PID = %d\n", getpid());
}
else {
printf("This is parent process %d\n", getpid());
sleep(30);
wait(0);
}
}
