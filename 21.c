/*
============================================================================
Name : 21.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to call fork and print the parent and child process id.
Date: 1st Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(){
int id;

id= fork();

if(id==0){
	printf("Child Process: PID- %d , Parend ID- %d\n", getpid(), getppid());}
else{
	printf("Parent Process: PID- %d, Child ID- %d\n", getpid(), id);
}
return 0;
}
