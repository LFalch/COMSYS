#include <stdio.h>
#include <errno.h>

int read_int(FILE *f, int *out) {
    return fread(out, sizeof(int), 1, f) == 1 ? 0 : 1;
}

int main(int argc, char const *argv[]) {
    if (argc > 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    FILE *f = argc == 2 ? fopen(argv[1], "rb") : stdin;

    if (f == NULL) {
        perror("Couldn't open file");
        return 1;
    }

    int i;
    while (read_int(f, &i) == 0) {
        printf("%d\n", i);
    }

    int exitStatus = 0;
    if (errno != 0) {
        perror("Error: ");
        exitStatus = 1;
    }

    fclose(f);

    return exitStatus;
}
