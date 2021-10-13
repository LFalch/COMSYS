#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <semaphore.h>

static void *thread(void *);
static sem_t lock;

int main(int argc, char const *argv[]) {
    int n = atoi(argv[argc-1]);

    pthread_t *pts = malloc(n * sizeof(sizeof(pthread_t)));
    sem_init(&lock, 0, 0);

    for (int i = 0; i < n; i++) {
        assert(pthread_create(&pts[i], NULL, thread, NULL) == 0);
    }
    sem_post(&lock);
    for (int i = 0; i < n; i++) {
        assert(pthread_join(pts[i], NULL) == 0);
    }
    return 0;
}

static char hello[] = "Hello, world!\n";

static void *thread(void *vargp) {
    sem_wait(&lock);
    sem_post(&lock);
    for (size_t i = 0; i < sizeof(hello); i++) {
        putchar(hello[i]);
    }
    return NULL;
}
