#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH      100

void usage(void);

const char *prog_name;

int
main(int argc, char *argv[])
{
    int max;    /* random number must be between 0 and max */
    int n;      /* randome number */
    int g;      /* guessed number */
    int t;      /* number of tries */
    char s[LENGTH];
    
    prog_name = argv[0];
    if (argc > 2) {
        usage();
        exit(1);    /* unreachable */
    }
    else if (argc == 2) {        
        if ((max = (int) strtol(argv[1], NULL, 10)) <= 0) {
            usage();
            exit(1);    /* unreachable */
        }
    }
    else
        max = RAND_MAX;
    
    srand(time(NULL));
    n = rand() % max;
    t = 0;
    
    do {
        if (scanf("%s", s) == EOF) {
            fprintf(stderr, "no more input.\n");
            exit(0);
        }
        t++;        
        if (n > (g = strtol(s, NULL, 10)))
            printf("[%10d] try #%-3d: go up\n", g, t);
        else if (n < g)
            printf("[%10d] try #%-3d: go down\n", g, t);
    } while (g != n);
    
    printf("[%10d] try #%-3d: WOOW %d IS CORRECT.\n", g, t, n);
    
    return t;
}

void
usage(void)
{
    fprintf(stderr, "usage: %s [max]\n", prog_name);
    exit(1);
}