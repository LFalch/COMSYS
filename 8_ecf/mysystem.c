#include "mysystem.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int mysystem(char* command) {
    pid_t pid;
    if ((pid = fork()) == 0) {
        execl("/bin/sh", "sh", "-c", command, NULL);
        // if we return, then something went wrong, let's just exit
        perror("Error excecuting the command");
        abort();
    }
    int wstaus;
    waitpid(pid, &wstaus, 0);
    if (WIFEXITED(wstaus)) {
        return WEXITSTATUS(wstaus);
    }
    abort();
}
