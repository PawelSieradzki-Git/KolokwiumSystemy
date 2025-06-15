#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "agent.h"

void handle_signal(int signal) {
    if (signal == SIGUSR1) {
        printf("Czekam na rozkazy\n");
    } else if (signal == SIGUSR2) {
        printf("Rozpoczynam misję\n");
    } else if (signal == SIGTERM) {
        printf("Misja zakończona\n");
        exit(EXIT_SUCCESS);
    }
}

void agent_logic(const char *name) {
    printf("%s: Gotowy do misji\n", name);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    signal(SIGTERM, handle_signal);

    char command[256];
    while (1) {
        if (fgets(command, sizeof(command), stdin)) {
            if (strncmp(command, "Identify!", 9) == 0) {
                printf("My codename is %s\n", name);
            } else if (strncmp(command, "Status?", 7) == 0) {
                printf("%s: My PID is: %d\n", name, getpid());
            }
        }
    }
}