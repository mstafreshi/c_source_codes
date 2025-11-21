#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

/* mh_trim: trim a string based on flag */
char *
mh_trim(char *s, int flags)
{
    if (flags & MH_TRIM_BOTH)
        flags = ~MH_TRIM_BOTH | MH_TRIM_LEFT | MH_TRIM_RIGHT;
    
    if (flags & MH_TRIM_LEFT)
        mh_ltrim(s);
    if (flags & MH_TRIM_RIGHT)
        mh_rtrim(s);
    return s;
}

char *
mh_ltrim(char *s)
{
    char *p;
    
    p = s;
    while (isspace(*p))
        p++;
    if (p != s)
        memmove(s, p, strlen(p) + 1);       /* first use of memmove! */
    return s;
}

char *
mh_rtrim(char *s)
{
    int i, n;
    
    n = -1;
    for (i = 0; s[i] != '\0'; i++)
        if (! isspace(s[i]))
            n = -1;
        else if (n == -1)
            n = i;
    
    if (n != -1)
        s[n] = '\0';
    return s;
}

/*
 * mh_chop: perl like chop function.
 * return and remove last character of string
 */
int
mh_chop(char *s)
{
    int i;
    int temp = '\0';
    
    for (i = 0; s[i] != '\0'; i++)
        ;
    if (i) {
        temp = s[i - 1];
        s[i - 1] = '\0';
    }
    return temp;
}

/*
 * mh_uc: convert string to upper case.
 */
char *
mh_uc(char *s)
{
    int i;
    
    for (i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);
    return s;
}

/*
 * mh_lc: convert string to lower case.
 */
char *
mh_lc(char *s)
{
    int i;
    
    for (i = 0; s[i] != '\0'; i++)
        s[i] = tolower(s[i]);
    return s;
}

/*
 * mh_lcfirst: convert first char of string to lower case.
 */
char *
mh_lcfirst(char *s)
{
    if (s[0] != '\0')
        s[0] = tolower(s[0]);
    return s;
}

/*
 * mh_ucfirst: convert first char of string to upper case.
 */
char *
mh_ucfirst(char *s)
{
    if (s[0] != '\0')
        s[0] = toupper(s[0]);
    return s;
}

/*
 * mh_substr.
 * 
 * result will be placed in p that must be big enough.
 */
char *
mh_substr(char *s, int start, int length, char *p)
{
    int i;
    int j;
    
    if (start < 0)
        start = strlen(s) + start;
    if (length <= 0) {
        p[0] = '\0';
        return p;
    }
    for (i = start, j = 0; i < start + length; )
        p[j++] = s[i++];
    p[j] = '\0';
    return p;
}

char *
mh_reverse(char *s)
{
    int i, j, temp;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}