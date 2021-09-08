#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            perror("Could not open file in read mode");
        } else {
            printf("%s opened succesfully\n", argv[i]);
            fclose(f);
        }
    }

    return 0;
}
