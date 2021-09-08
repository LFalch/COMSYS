#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            perror("Could not open file in read mode");
        } else {
            char buffer[1024];
            for (;;) {
                int read = fread(buffer, sizeof(char), 1024, f);
                if (read == 0) {
                    if (feof(f)) {
                        break;
                    } else {
                        perror("Could not read from file");
                    }
                }

                for (int i = 0; i < read; i++) {
                    if (buffer[i] == 'A') {
                        printf("No A's are allowed!\n");
                        return 1;
                    }
                }
            }
            fclose(f);
            printf("Ok\n");
        }
    }

    return 0;
}
