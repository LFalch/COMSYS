#include "mysystem.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("- Running %s:\n", argv[i]);
        int exitStatus = mysystem(argv[i]);
        printf("- Exit code: %d\n\n", exitStatus);
    }
}
