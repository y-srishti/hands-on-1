/*
============================================================================
Name : 13.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not.
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    struct timeval timeout;
    timeout.tv_sec = 10; // Wait for 10 seconds
    timeout.tv_usec = 0;

    printf("Waiting for input from STDIN for 10 seconds...\n");

    select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        printf("Input is available!\n");
    } else {
        printf("No input received within 10 seconds.\n");
    }

    return 0;
}

