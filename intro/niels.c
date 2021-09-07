#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int secret = rand() % 100;
    int guess = -1;
    int guesses = 0;

    printf("*** GUESSING GAME!! ***\n    Welcome!\n\n");
    for (;;) {
        printf("Try a number: ");
        fflush(stdout);
        if (scanf("%d", &guess) == 1) {
            guesses++;
            if (guess > secret) {
                printf("Too high. Try again.\n");
            } else if (guess < secret) {
                printf("Too low. Try again.\n");
            } else {
                break;
            }
        } else {
            printf("Incorrect number format!\n");
            while (getchar() != '\n') {}
        }
    }
    printf("You guessed right! The secret was indeed %d! It took you %d guesses.\n", secret, guesses);
    return 0;
}
