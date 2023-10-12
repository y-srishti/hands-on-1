/*
============================================================================
Name : 30.c
Author : Srishti Yadav
Description : Write a C, Ansi-style program to run a script at a specific time using a Daemon process.
Date: 8th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void runScript() {
    
    system("your_script.sh");
}

void* daemonProcess(void* arg) {
    struct tm targetTime = {0};
    targetTime.tm_hour = 2;
    targetTime.tm_min = 0;
    targetTime.tm_sec = 0;

    // Infinite loop to check the current time and run the script when it's time
    while (1) {
        // Get the current time
        time_t now;
        time(&now);
        struct tm* currentTime = localtime(&now);

        // Check if the current time matches the target time
        if (currentTime->tm_hour == targetTime.tm_hour && currentTime->tm_min == targetTime.tm_min) {
            // Run the script
            runScript();

            sleep(60); // Sleep for 60 seconds
        }

        sleep(10); // Sleep for 10 seconds
    }

    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, daemonProcess, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);

    return 0;
}
