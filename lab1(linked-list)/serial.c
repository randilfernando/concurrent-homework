
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./linked_list.h"

struct operation {
    int method_number;
    int random_number;
};

struct list_node_s *h = NULL;

int member_count, insert_count, delete_count;

/*
 * get random value
 */
int getRandom() {
    return rand() % 65536;
}

/*
 * test functions
 */
void Test() {
    while (member_count > 0 || insert_count > 0 || delete_count > 0) {
        int condition = rand() % 3;
        if (condition == 0 && member_count > 0) {
            Member(getRandom(), h);
            member_count--;
        } else if (condition == 1 && insert_count > 0) {
            Insert(getRandom(), &h);
            insert_count--;
        } else if (condition == 2 && delete_count > 0) {
            Delete(getRandom(), &h);
            delete_count--;
        }
    }
}

int main(int argc, char **argv) {
    srand((unsigned) time(NULL));
    int n, m;

    n = (int) strtol(argv[1], NULL, 10);
    m = (int) strtol(argv[2], NULL, 10);

    member_count = (int) (strtof(argv[3], NULL) * m);
    insert_count = (int) (strtof(argv[4], NULL) * m);
    delete_count = (int) (strtof(argv[5], NULL) * m);

    //populate
    for (int i = 0; i < n; i++) {
        Insert(getRandom(), &h);
    }

    clock_t start = clock();

    //calculate execution time
    Test();

    clock_t end = clock();

    double difference = (end - start) / (double) CLOCKS_PER_SEC;

    printf("Time elapsed: %f\n", difference);

    return 0;
}
