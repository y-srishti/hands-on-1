/*
============================================================================
Name : 1c.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create a FIFO file using system call.
Date: 11th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifoPath = "myfifo";
    int result = mkfifo(fifoPath, S_IRUSR | S_IWUSR);
    if (result == 0) {
        printf("FIFO created successfully.\n");
    } else {
        perror("Error creating FIFO");
    }

    return 0;
}

