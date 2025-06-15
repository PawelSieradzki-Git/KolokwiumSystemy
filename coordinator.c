#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "coordinator.h"

void start_agents() {
    char *agents[] = {"Gamma", "Beta", "Alpha", "Delta"};
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            execl("./agent", agents[i], NULL);
            perror("execl failed");
            exit(EXIT_FAILURE);
        }
    }
}