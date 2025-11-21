#ifndef _MYHEADER_H
#define _MYHEADER_H

#define MH_TRIM_LEFT    0x01
#define MH_TRIM_RIGHT   0x02
#define MH_TRIM_BOTH    0x04

void mh_selection_sort(int numbers[], int n);
void mh_bubble_sort(int numbers[], int n);
void mh_quick_sort(int numbers[], int low, int high);
void mh_swap(int numbers[], int i, int j);
char *mh_tobin(long int n, char *s, int l);  /* l = s array length */
char *mh_trim(char *s, int flags);
char *mh_rtrim(char *s);
char *mh_ltrim(char *s);
int mh_chop(char *s);
char *mh_uc(char *s);
char *mh_lc(char *s);
char *mh_lcfirst(char *s);
char *mh_ucfirst(char *s);
char *mh_substr(char *source, int start, int length, char *destination);
char *mh_reverse(char *s);

#endif