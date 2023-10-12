/*
============================================================================
Name : 25.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 1st Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int child_count = 3;
    int child_pid[child_count];
    int status;

    for (int i = 0; i < child_count; i++) {
        child_pid[i] = fork();

        if (child_pid[i] == -1) {
            printf("error in fork");
            exit(1);
        }

        if (child_pid[i] == 0) {
            printf("Child %d (PID: %d) is running.\n", i + 1, getpid());
            sleep(2); 
            exit(0); 
        }
    }

    int target_child = 2;

    printf("Parent (PID: %d) is waiting for Child %d (PID: %d).\n", getpid(), target_child + 1, child_pid[target_child]);

    pid_t terminated_child = waitpid(child_pid[target_child], &status, 0);

    if (terminated_child == -1) {
        perror("waitpid");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("Parent: Child %d (PID: %d) terminated with status %d.\n", target_child + 1, terminated_child, WEXITSTATUS(status));
    }

    return 0;
}

