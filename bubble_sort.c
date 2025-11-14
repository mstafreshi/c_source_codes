#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "myheader.h"

int
main(int argc, char *argv[])
{
    int *to_be_sorted, *numbers;
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
        to_be_sorted[i] = numbers[i] = rand() % 10000;
    
    mh_bubble_sort(to_be_sorted, n);   /* sort array */
    
    printf("%8s %8s\n", "numbers", "sorted");
    for (i = 0; i < n; i++)
        printf("%8d %8d\n", numbers[i], to_be_sorted[i]);
    
    return 0;
}