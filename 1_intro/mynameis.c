#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = getenv("USER");
    if (name == NULL)
        return 1;
    printf("%s\n", name);
    return 0;
}
