#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong number of arguments!\n");
        return 1;
    }
    if (argv[1][0] == 'A') {
        printf("No beginning A's are allowed\n");
        return 2;
    }
    printf("%s\n", argv[1]);
    return 0;
}
