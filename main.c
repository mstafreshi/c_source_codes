#include <stdio.h>
#include <string.h>
#include "myheader.h"

int
main(int argc, char *argv[])
{
    char s[] = "samla";
    char p[BUFSIZ];
    
    printf("<%s>\n", mh_reverse(s));
    //printf("%s", s);
    return 0;
}