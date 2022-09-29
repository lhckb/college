#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dispatch/dispatch.h>

// #define BUFFER_SIZE 512

dispatch_semaphore_t empty;
dispatch_semaphore_t full;

pthread_mutex_t mutex;

int in = 0, out = 0;
int N = 0, B = 0;
int C = 0, P = 0;

int *buffer;

void *producer(void *pno);
void *consumer(void *cno);

int main(void) {
    printf("P, C, B, N\n");
    scanf("%d %d %d %d", &P, &C, &B, &N);

    // TODO check if operations were successfull

    pthread_t *producers = (pthread_t*) malloc(sizeof(pthread_t) * P);
    pthread_t *consumers = (pthread_t*) malloc(sizeof(pthread_t) * C);

    buffer = (int*) malloc(sizeof(int) * B);

    pthread_mutex_init(&mutex, NULL);
    empty = dispatch_semaphore_create(0);
    full = dispatch_semaphore_create(B);

    // array containing ....
    int size = P > C ? P : C;
    int *index = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        index[i] = i;
    }

    for (int i = 0; i < P; i++) {
        pthread_create(&producers[i], NULL, producer, &index[i]);
    }

    for (int i = 0; i < C; i++) {
        pthread_create(&consumers[i], NULL, consumer, &index[i]);
    }

    for (int i = 0; i < P; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < C; i++) {
        pthread_join(consumers[i], NULL);
    }

    free(producers);
    free(consumers);
    free(index);
    return 0;
}

void *producer(void *pno) {
    int *id = pno;
    int input;
    while (1) {
        for (int i = 0; i <= N; i++) {
            input = 2 * i + 1;
            dispatch_semaphore_wait(full, DISPATCH_TIME_FOREVER);
            pthread_mutex_lock(&mutex);
            buffer[in] = input;
            printf("Producer %d Input %d at index %d\n", *id, input, in);
            in = (in + 1) % B;
            pthread_mutex_unlock(&mutex);
            dispatch_semaphore_signal(empty); 
        }
    }
}

void *consumer(void *cno) {
    int *id = cno;
    int output;
    while (1) {
        dispatch_semaphore_wait(empty, DISPATCH_TIME_FOREVER);
        pthread_mutex_lock(&mutex);
        output = buffer[out];
        printf("Consumer %d output %d at index %d\n", *id, output, out);
        out = (out + 1) % B;
        pthread_mutex_unlock(&mutex);
        dispatch_semaphore_signal(full);
    }
}