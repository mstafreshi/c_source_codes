#include <stdio.h>
#include <string.h>
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



/*
 * mh_tobin: convert intger n to binary format and
 * return it as an array of characters.
 * =================================================
 * long int n: number to be converetd to binary
 * char *s   : array of characters; binary will be saved here
 * int l     : length of s array
 * =================================================
 * returns   : pointer to first non zero index
 */
char *
mh_tobin(long int n, char *s, int l)
{
    int i, j;
    char *first_non_zero_bit;
    
    if (n < 0) {
        fprintf(stderr, 
            "%s: %ld is negative!\n", __FUNCTION__, n);
        return NULL;
    }
    
    j = 0;
    memset(s, 0, l);
    for (i = sizeof(n) * 8 - 1; i >= 0 ; i--, j++) {
        s[j] = '0' + ((n >> i) & 1);
    }
    s[j] = '\0';
    
    for (i = 0, first_non_zero_bit = NULL; i < j; i++)
        if (s[i] == '1')
            return &s[i];
        
    return j - 1 >= 0 ? &s[j - 1] : NULL;   /* just 0 can reach here */
}
