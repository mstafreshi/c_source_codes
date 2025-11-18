#ifndef _MYHEADER_H
#define _MYHEADER_H

void mh_selection_sort(int numbers[], int n);
void mh_bubble_sort(int numbers[], int n);
void mh_quick_sort(int numbers[], int low, int high);
void mh_swap(int numbers[], int i, int j);
char *mh_tobin(long int n, char *s, int l);  /* l = s array length */
#endif