#include <errno.h>
#include <stdio.h>

#define checkFile(f)                  \
    if (f == NULL) {                  \
        perror("Couldn't open file"); \
        return 1;                     \
    }

int read_ascii_int(FILE *f, int *out) {
    *out = 0;
    for (;;) {
        int a = getc(f);
        if (a == EOF) return 1;

        unsigned char c = a;

        if (c >= '0' && c <= '9') {
            *out = (*out) * 10 + (int)(c - '0');
        } else if (c == '\n')
            return 0;
        else
            return 1;
    }
}

int main(int argc, char const *argv[]) {
    if (argc > 3 || argc < 2) {
        printf("Usage: %s [ints.txt] <ints.bin>\n", argv[0]);
        return 1;
    }

    FILE *ints = argc == 3 ? fopen(argv[1], "r") : stdin;
    checkFile(ints);
    FILE *out_bin = fopen(argc == 3 ? argv[2] : argv[1], "wb");
    checkFile(out_bin);

    int i;
    while (read_ascii_int(ints, &i) == 0) {
        printf("%d\n", i);
        if (fwrite(&i, sizeof(int), 1, out_bin) != 1) break;
    }
    int exitStatus = 0;
    if (errno != 0) {
        perror("Error: ");
        exitStatus = 1;
    }

    fclose(ints);
    fclose(out_bin);

    return exitStatus;
}
