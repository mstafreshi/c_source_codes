#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"

#define ARRAY_LENGTH    100

int
main(int argc, char *argv[])
{
    char s[ARRAY_LENGTH];   /* converted number will be saved here */
    char *f;                /* will point to first non zero bit */
    long int n;
    
    for (argv++; *argv != NULL; argv++) {
        n = strtol(*argv, NULL, 0);
        if (f = mh_tobin(n, s, ARRAY_LENGTH))
            printf("%s=%s=%ld=0%lo=0x%lx\n",
                *argv, f, n, n, n);
    }
    return 0;
}