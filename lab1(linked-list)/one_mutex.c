#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./linked_list.h"

pthread_mutex_t mutex;

int thread_count, member_count, insert_count, delete_count;
struct list_node_s *h = NULL;
int operations[10000] = {};

/*
 * get random value
 */
int getRandom() {
    return rand() % 65536;
}

void *Test(void *rank) {
    int my_rank = (int)(long) rank;
    int range = 10000 / thread_count;
    int start_pos = my_rank * range;

    for (int i = start_pos; i < start_pos + range; i++) {
        switch (operations[i]) {
            case 0:
                pthread_mutex_lock(&mutex);
                Member(getRandom(), h);
                pthread_mutex_unlock(&mutex);
                break;
            case 1:
                pthread_mutex_lock(&mutex);
                Insert(getRandom(), &h);
                pthread_mutex_unlock(&mutex);
                break;
            case 2:
                pthread_mutex_lock(&mutex);
                Delete(getRandom(), &h);
                pthread_mutex_unlock(&mutex);
                break;
        }
    }
};

void Generate_Array() {
    for (int i = 0; i < member_count; i++) {
        operations[i] = 0;
    }

    for (int i = member_count; i < member_count + insert_count; i++) {
        operations[i] = 1;
    }

    for (int i = member_count + insert_count; i < 10000; i++) {
        operations[i] = 2;
    }

    for (int i = 0; i < 10000; i++) {
        int pos1 = rand() % 10000;
        int pos2 = rand() % 10000;

        int temp = operations[pos1];
        operations[pos1] = operations[pos2];
        operations[pos2] = temp;
    }
}

int main(int argc, char *argv[]) {
    srand((unsigned) time(NULL));
    int n, m;

    thread_count = (int) strtol(argv[6], NULL, 10);
    n = (int) strtol(argv[1], NULL, 10);
    m = (int) strtol(argv[2], NULL, 10);

    member_count = (int) (strtof(argv[3], NULL) * m);
    insert_count = (int) (strtof(argv[4], NULL) * m);
    delete_count = (int) (strtof(argv[5], NULL) * m);

    //populate
    for (int i = 0; i < n; i++) {
        Insert(getRandom(), &h);
    }

    Generate_Array();

    //thread initialization
    long thread;
    pthread_t *thread_handles;

    thread_handles = malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    clock_t start = clock();

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Test, (void *) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    clock_t end = clock();

    double difference = (end - start) / (double) CLOCKS_PER_SEC;

    printf("Time elapsed: %f\n", difference);

    pthread_mutex_destroy(&mutex);
    free(thread_handles);
    return 0;
}