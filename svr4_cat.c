/*
 * This source code belongs to SYSVR4 cat command.
 * original code: 
 * https://github.com/calmsacibis995/svr4-src/blob/main/cmd/cat/cat.c
 */

#include    <stdio.h>
#include    <ctype.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <locale.h>
#include    <stdlib.h>
#include    <getopt.h>
#include    <unistd.h>

#define IDENTICAL(A, B)     (A.st_dev == B.st_dev && A.st_ino == B.st_ino)

int vcat(FILE *fi);
int cat(FILE *fi);

char    buffer[BUFSIZ];

int silent = 0;
int visi_mode = 0;
int visi_tab = 0;
int visi_newline = 0;
int errnbr = 0;

int
main(int argc, char *argv[])
{
    register FILE *fi;
    register int c;
    extern int optind;  /* check it */
    int errflg = 0;
    int stdinflg = 0;
    int status = 0;
    struct stat source, target;

    (void) setlocale(LC_ALL, "");   /* check it */
#ifdef STANDALONE
    if (argv[0][0] == '\0')
        argc = getargv("cat", &argv, 0);    /* check it */
#endif
    
    while ((c = getopt(argc, argv, "usvte")) != -1) {
        switch (c) {
        case 'u':
#ifndef STANDALONE
            setbuf(stdout, (char *) NULL);  /* check it */
#endif 
            continue;

        case 's':
            silent++;
            continue;

        case 'v':
            visi_mode++;
            continue;

        case 't':
            visi_tab++;
            continue;

        case 'e':
            visi_newline++;
            continue;

        case '?':
            errflg++;
            break;
        }
        break;
    }

    if (errflg) {
        if (!silent)
            fprintf(stderr, "usage: cat -usvte [-|file] ...\n");
        exit(2);
    }

    if (fstat(fileno(stdout), &target) < 0) {    /* check it */
        if (!silent)
            fprintf(stderr, "cat: cannot stat stdout\n");
        exit(2);
    }

    if (optind == argc) {
        argc++;
        stdinflg++;
    }
    
    for (argv = &argv[optind];
      optind < argc && !ferror(stdout); optind++, argv++) {
        if (stdinflg || ((*argv)[0] == '-' && (*argv)[1] == '\0'))
            fi = stdin;
        else {
            if ((fi = fopen(*argv, "r")) == NULL) {
                if (!silent)
                    fprintf(stderr, "cat: cannot open %s\n", *argv);
                status = 2;
                continue;
            }
        }

        if (fstat(fileno(fi), &source) < 0) {
            if (!silent)
                fprintf(stderr, "cat: cannot stat %s\n", *argv);
            status = 2;
            continue;
        }

        /* what does this block of code? */
        if (!S_ISCHR(target.st_mode)
          && !S_ISBLK(target.st_mode)
          && IDENTICAL(target, source)) {
            if (!silent)
                fprintf(stderr, "cat: input/output files '%s' identical\n",
                  stdinflg ? "-" : *argv);
            if (fclose(fi) != 0)
                fprintf(stderr, "cat: close error\n");
            status = 2;
            continue;
        }

        if (visi_mode)
            status = vcat(fi);
        else
            status = cat(fi);

        if (fi != stdin) {
            fflush(stdout);
            if (fclose(fi) != 0)
                if (!silent)
                    fprintf(stderr, "cat: close error\n");
        }
    }

    fflush(stdout);

    if (errnbr = ferror(stdout)) {
        if (!silent) {
            fprintf(stderr, "cat: output error (%d)\n", errnbr);
            perror("");
        }
        status = 2;
    }
    exit(status);
}

int
cat(FILE *fi)
{
    register int fi_desc;
    register int ntimes;

    fi_desc = fileno(fi);
    while ((ntimes = read(fi_desc, buffer, BUFSIZ)) > 0) {
        if ((errnbr = write(1, buffer, (unsigned) ntimes)) != ntimes) {
            if (!silent) {
                if (errnbr == -1)
                    errnbr = 0;
                fprintf(stderr,
                  "cat: output error (%d/%d) characters written\n",
                  errnbr, ntimes);
                perror("");
            }
            return 2;
        }
    }
    return 0;
}

int
vcat(FILE *fi)
{
    register int c;

    while ((c = getc(fi)) != EOF) {
        if (!isprint(c) && !iscntrl(c)) {
            putchar('M');
            putchar('-');
            c -= 0200;  /* check this */
        }
        if (isprint(c)) {
            putchar(c);
            continue;
        }
        if ((c == '\t') || (c == '\f')) {
            if (!visi_tab)
                putchar(c);
            else {
                putchar('^');
                putchar(c^0100);    /* check this */
            }
            continue;
        }
        if (c == '\n') {
            if (visi_newline)
                putchar('$');
            putchar(c);
            continue;
        }

        if (c < 0200) {
            putchar('^');
            putchar(c ^ 0100);
        }
        else {
            putchar('M');
            putchar('-');
            putchar('x');
        }
    }
    return 0;
}
