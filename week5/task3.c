#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define Buffer_Limit 100000

int buf_index_value = 0;
int *Buffer;

pthread_mutex_t mutex_variable = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buf_queue_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buf_queue_not_empty = PTHREAD_COND_INITIALIZER;

void *Consumer() {
    while (1) {
        pthread_mutex_lock(&mutex_variable);
        if (buf_index_value == -1) {
            pthread_cond_wait(&buf_queue_not_empty, &mutex_variable);
        }
        printf("\nConsumer:%d\t", buf_index_value--);
        pthread_mutex_unlock(&mutex_variable);
        pthread_cond_signal(&buf_queue_not_full);
    }
}

void *Producer() {
    while (1) {
        pthread_mutex_lock(&mutex_variable);
        if (buf_index_value == Buffer_Limit) {
            pthread_cond_wait(&buf_queue_not_full, &mutex_variable);
        }
        Buffer[buf_index_value++] = 1;
        printf("\nProducer:%d\t", buf_index_value);
        pthread_mutex_unlock(&mutex_variable);
        pthread_cond_signal(&buf_queue_not_empty);
    }
}

int main() {
    pthread_t producer_thread_id, consumer_thread_id;
    Buffer = (int *) malloc(sizeof(int) * Buffer_Limit);
    pthread_create(&producer_thread_id, NULL, Producer, NULL);
    pthread_create(&consumer_thread_id, NULL, Consumer, NULL);
    pthread_join(producer_thread_id, NULL);
    pthread_join(consumer_thread_id, NULL);
    return 0;
}