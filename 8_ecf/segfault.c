#include <stdio.h>

int main() {
    printf("%d\n", *((volatile int *) NULL));
}
