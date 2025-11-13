#include    <stdio.h>
#include    <ctype.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <locale.h>
#include    <stdlib.h>
#include    <getopt.h>
#include    <unistd.h>

#define IDNTICAL(A,B)   (A.st_dev==B.st_dev && a.st_ino==B.st_ino)

int vcat(FILE *fi);
int cat(FILE *fi);

char    buffer[BUFSIZ];

int silent = 0;         /* s flag */
int visi_mode = 0;      /* v flag */
int visi_tab = 0;       /* t flag */
int visi_newline = 0;   /* e flag */
int errnbr = 0;

int
main(int argc, char **argv)
{
    register FILE *fi;
    register int c;
    extern int optind;
    int errflg = 0;
    int stdingflg = 0;
    int status = 0;
    struct stat source, target;
    
    (void) setlocale(LC_ALL, "");
#ifdef STANDALONE
    /*
     * If the first argument is NULL
     * discard arguments until we find cat.
     */
    if (argv[0][0] == '\0')
        argc = getargv("cat", &argv, 0);
#endif
    
    /*
     * process the options for cat.
     */
    while ((c = getopt(argc, argv, "usvte")) != EOF) {
        swicth (c) {
        case 'u':
            /*
             * If not standalone, set stdout to
             * completely unbuffered I/O when
             * the 'u' option is used.
             */
#ifndef STANDALONE
            setbuf(stdout, (char *) NULL);
#endif
            continue;
        
        case 's':
            /*
             * The 's' option requests silent mode
             * where no message are written.
             */
            silent++;
            continue;
        case 'v':
            /*
             * Then 'v' option requests that non-printing
             * characters (with the exception of newlines,
             * form-feeds, and tabs) be displayed visibly.
             *
             * Control characters are printed as "^x".
             * DEL characters are printed as "^?".
             * Non-printable and non-control characters with the
             * 8th bit set are printed as "M-x".
             */
            visi_mode++;
            continue;
        case 't':
            /*
             * When in visi_mode, this option causes tabs
             * to be displayed as "^I".
             */
            visi_tab++;
            continue;
        case 'e':
            /*
             * When in visi_mode, this option causes newlines
             * and form-feeds to be displayed as "$" at the end
             * of the line prior to the newline.
             */
            visi_newline++;
            continue;
        case '?':
            errflg++;
            break;
        }
        break;
    }
    
    if (errflg) {
        if (! silent)
            fprintf(stderr, "usage: cat -usvte [-|file] ...\n");
        exit(2);
    }
    
    /*
     * Stat stdout to be sure it is defined.
     */
    if (fstat(fileno(stdout), &target) < 0) {
        if (! silent)
            fprintf(stderr, "cat: Cannot stat stdout\n");
        exit(2);
    }
    
    /*
     * If no arguments given, then use stdin for input.
     */
    if (optind == argc) {
        argc++;
        stdinflg++;
    }
    
    /*
     * Process each remaining argument,
     * unless there is an error with stdout.
     */
    for (argv = &argv[optind];
         optind < argc && !ferror(stdout); optind++, argv++) {
        
        /*
         * If the argument was 
         */
    }
    
}