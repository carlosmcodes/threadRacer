#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
/**
 * THESE DEFINE VALUES CANNOT BE CHANGED.
 * DOING SO WILL CAUSE POINTS TO BE DEDUCTED
 * FROM YOUR GRADE
 */
/** BEGIN VALUES THAT CANNOT BE CHANGED */
#define MAX_THREADS 36
#define MAX_ITERATIONS 22
/** END VALUES THAT CANNOT BE CHANGED */


/**
 * use this struct as a parameter for the
 * nanosleep function.
 * For exmaple : nanosleep(&ts, NULL);
 */
struct timespec ts = {0, 150000};

void *thread_add(void *arg);

void *thread_sub(void *arg);

int val = 0;

int main(int argc, char **argv) {
    pthread_t tid[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&tid[i], NULL, thread_add, (void *) &val);
        } else {
            pthread_create(&tid[i], NULL, thread_sub, (void *) &val);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(tid[i], NULL);
        nanosleep(&ts, NULL);
    }
    printf("Final Value of Shared Variable : %d\n", val);
    return 0;
}

void *thread_add(void *arg) {
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        int temp = *((int *) arg);
        temp += 10;
        nanosleep(&ts, NULL);
        val = temp;
        printf("Current Value written to Global Variables by ADDER thread id: %lu is %d\n", pthread_self(), temp);
    }
}

void *thread_sub(void *arg) {
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        nanosleep(&ts, NULL);
        int temp = *((int *) arg);
        temp -= 10;
        val = temp;
        printf("Current Value written to Global Variables by SUBTRACTOR thread id: %lu is %d\n", pthread_self(), temp);

    }
}