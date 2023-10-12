/*
============================================================================
Name : 29.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy
    int result = sched_getscheduler(0); // 0 represents the calling process (current process)
    if (result == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    policy = result;

    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
    }

    // Modify the scheduling policy to SCHED_FIFO
    param.sched_priority = 50; // Set the priority (adjust as needed)
    result = sched_setscheduler(0, SCHED_FIFO, &param);
    if (result == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Scheduling policy modified to SCHED_FIFO\n");

    return 0;
}

