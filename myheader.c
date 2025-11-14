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

/* mh_bubble_sort: sort an integer array with bubble sort algorithm. */
void
mh_bubble_sort(int numbers[], int n)
{
    int i, j;
    
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (numbers[j] > numbers[j + 1])
                mh_swap(numbers, j, j + 1);
        }
    }
}

/* mh_quick_sort: sort an integer array with quick sort algorithm. */
void
mh_quick_sort(int numbers[], int low, int high)
{
    int i, j, pivot;
    
    pivot = high;
    i = low;
    j = high - 1;
    
    if (low >= high)
        return;
    
    while (1) {
        for ( ; i < high; i++)
            if (numbers[i] >= numbers[pivot])
                break;
            
        for ( ; j >= low; j--)
            if (numbers[j] < numbers[pivot])
                break;

        if (i < j)
            mh_swap(numbers, i, j);
        else {
            mh_swap(numbers, i, pivot);
            break;
        }
    }
    mh_quick_sort(numbers, low, i - 1);
    mh_quick_sort(numbers, i + 1, high);
}