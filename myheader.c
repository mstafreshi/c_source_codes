#include "myheader.h"

/* 
 * mh_selection_sort
 * sort an integer array with selection sort algorithm.
 */
void
mh_selection_sort(int numbers[], int n)
{
    int i, j, max_index;
    
    for (i = n - 1; i >= 0; i--) {
        max_index = i;
        for (j = 0; j < i; j++)
            if (numbers[j] > numbers[max_index])
                max_index = j;
        if (max_index != i)
            mh_swap(numbers, i, max_index);
    }
}

/* mh_swap: swap two elements of an integer array */
void
mh_swap(int numbers[], int i, int j)
{
    int temp;
    
    temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}