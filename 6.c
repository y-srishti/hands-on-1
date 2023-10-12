/*
============================================================================
Name : 6.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 13th Aug, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main() {
	char buffer[1024];
	ssize_t bytesRead;

	int inputFD = 0; 
	int outputFD = 1;

	bytesRead = read(inputFD, buffer, sizeof(buffer));
	if (bytesRead < 0) {
        printf("Error reading from STDIN");
        return 1;
	}

	ssize_t bytesWritten = write(outputFD, buffer, bytesRead);
        if (bytesWritten < 0) {
        printf("Error writing to STDOUT");
        return 1;
        }
        return 0;
}
