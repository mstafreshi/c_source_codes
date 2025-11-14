#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "myheader.h"

int
main(int argc, char *argv[])
{
    int *numbers, *to_be_sorted;
    int i, n;
    
    if (argc != 2 || (n = atoi(argv[1])) <= 0) {
        fprintf(stderr,
            "usage: %s random_numbers_to_be_generated\n", argv[0]);
        exit(1);
    }
    
    numbers = (int *) calloc(n, sizeof(int));
    to_be_sorted = (int *) calloc(n, sizeof(int));
    
    if (numbers == NULL || to_be_sorted == NULL) {
        perror(argv[0]);
        exit(1);
    }
    
    srand(time(NULL));
    for (i = 0; i < n; i++)
        numbers[i] = to_be_sorted[i] = rand() % 100000000;
    mh_quick_sort(to_be_sorted, 0, n - 1);
    
    printf("%8s %8s\n", "numbers", "sorted");
    for (i = 0; i < n; i++)
        printf("%8d %8d\n", numbers[i], to_be_sorted[i]);
    
    return 0;
}