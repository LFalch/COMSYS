#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value> <index>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long value = strtoll(argv[1], NULL, 0);
    long long index = strtol(argv[2], NULL, 0);

    if (errno == EINVAL || errno == ERANGE) {
        printf("Invalid number\n");
        return EXIT_FAILURE;
    }

    if (index > 63 || index < 0) {
        printf("Index out of bounds!\n");
        return EXIT_FAILURE;
    }

    value = value ^ (1LL << index);

    printf("%lld\n", value);

    return EXIT_SUCCESS;
}
