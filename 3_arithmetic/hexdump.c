#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char* ends[8] = {" ", " ", " ", " ", " ", " ", " ", "  "};

    FILE* file = fopen(argv[1], "rb");

    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", strerror(errno));
        return 1;
    }

    char bytes[16];
    int index = 0;

    for (;;) {
        int read = fread(bytes, sizeof(char), 16, file);
        if (read <= 0) {
            if (feof(file)) break;
            fprintf(stderr, "Could not read file: %s\n", strerror(errno));
            fclose(file);
            return 1;
        }
        printf("%08x  ", index);
        for (int i = 0; i < read; i++) {
            printf("%02x%s", bytes[i], ends[i & 7]);
            index++;
        }
        if (read != 16) {
            int spaces = 2 + (16 - read) * 3 + read / 8;
            for (int i = 0; i < spaces; i++)
                putchar(' ');
        }
        putchar('|');
        for (int i = 0; i < read; i++) {
            char c = bytes[i];
            if (c < 0x20 || c >= 0x7f)
                putchar('.');
            else
                putchar(c);
        }
        puts("|");
    }
    printf("%08x\n", index);

    fclose(file);

    return 0;
}
