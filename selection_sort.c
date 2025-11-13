#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myheader.h"

#define ARRAY_LENGTH    10

int
main()
{
    int i;
    int numbers[ARRAY_LENGTH];
    int to_be_sorted[ARRAY_LENGTH];
    
    srand(time(NULL));
    for (i = 0; i < ARRAY_LENGTH; i++) {
        numbers[i] = rand() % 10000;
        to_be_sorted[i] = numbers[i];
    }
    
    mh_selection_sort(to_be_sorted, ARRAY_LENGTH);
    
    printf("%8s %8s\n", "numbers", "sorted");
    for (i = 0; i < ARRAY_LENGTH; i++)
        printf("%8d %8d\n", numbers[i], to_be_sorted[i]);
    
    return 0;
}