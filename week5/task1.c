//
// Created by Maxim Sukach on 19/09/2018.
//

#include "stdio.h"
#include "pthread.h"
#include "unistd.h"
#define N 10

void *entry_point(void *arg){
    int id = *(int *)arg;
    sleep(1);
    printf("    Info from thread %d\n", id);
    printf("    Info[2] from thread %d\n", id);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int i;
    pthread_t thread[N];
    // Parallel
    printf("Parallel:\n");
    for (i = 0; i < N; i++) {
        printf("  Thread %d:\n", i);
        pthread_create(&thread[i], NULL, entry_point, (void *)&i);

    }
    for (i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }
    // Sequential
    printf("Sequential:\n");
    for (i = 0; i < N; i++) {
        printf("  Thread %d:\n", i);
        pthread_create(&thread[i], NULL, entry_point, (void *)&i);
        pthread_join(thread[i], NULL);

    }
    return 0;
}