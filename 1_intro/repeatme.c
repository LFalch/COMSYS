#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong number of arguments!\n");
        return 1;
    }
    printf("%s\n%s\n", argv[1], argv[1]);
    return 0;
}
