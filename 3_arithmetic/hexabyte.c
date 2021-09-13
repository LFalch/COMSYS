#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char ends[2] = {' ', '\n'};

    FILE* file = fopen(argv[1], "rb");

    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", strerror(errno));
        return 1;
    }

    char bytes[16];

    for(;;) {
        int read = fread(bytes, sizeof(char), 16, file);
        if (read <= 0) {
            if (feof(file)) break;
            fprintf(stderr, "Could not read file: %s\n", strerror(errno));
            fclose(file);
            return 1;
        }
        for (int i = 0; i < read; i++) {
            printf("%02x%c", bytes[i], ends[(i+1) >> 4]);
        }
    }
    puts("");

    fclose(file);

    return 0;
}
