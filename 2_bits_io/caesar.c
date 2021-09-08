#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[]) {
    assert(argc > 1);
    int offset = 1;
    if (argc > 2)
        sscanf(argv[2], "%d", &offset);

    const char *str = argv[1];

    for (int i = 0; str[i] != 0; i++) {
        printf("%c", (char) ((((int) str[i]) - ' ' + offset) % ('~' - ' ' + 1) + ' '));
    }
    puts("");

    return 0;
}
