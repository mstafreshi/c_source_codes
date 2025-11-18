#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int nflg = 0;           /* number each line? */

int
main(int argc, char *argv[])
{
    int c, i, cat(FILE *);
    void usage(const char *prog_name);
    FILE *fp;   
    char *prog_name;    /* for errors and usage function */
    
    prog_name = argv[0];
    opterr = 0;         /* not print default error by getopt */
    while ((c = getopt(argc, argv, "n")) != -1) {
        switch (c) {
        case 'n':
            nflg = 1;
            break;
        case '?':
            usage(prog_name);
            exit(1);    /* unreachable */
        }
    }
    argc -= optind;
    argv += optind;
    
    if (! argc)
        cat(stdin);
    else {
        for (i = 0; i < argc ; i++) {
            fp = fopen(argv[i], "r");
            if (! fp) {
                perror(argv[0]);
                continue;
            }
            cat(fp);
            fclose(fp);
        }
    }
    return 0;
}

int
cat(FILE *fp)
{
    int c, n, prev_char;
    static int line = 1;
    
    prev_char = 0;
    while ((c=getc(fp)) != EOF) {
        if ((prev_char == '\n' || prev_char == 0) && nflg)
            printf("%6d\t", line++);
        putc(prev_char = c, stdout);
        n++;
    }
    return n;
}

void
usage(const char *prog_name)
{
    fprintf(stderr, "usage: %s [-n] [filename[s]]\n", prog_name);
    exit(0);
}
