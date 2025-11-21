#include <stdio.h>
#include "myheader.h"

int
main(int argc, char *argv[])
{
    char s[] = "\t\t\t  \n  reza   \t\n";
    
    printf("<%s>\n", s);
    printf("<%s>\n", mh_trim(s, MH_TRIM_BOTH));
    printf("<%s>\n", s);
    
    return 0;
}