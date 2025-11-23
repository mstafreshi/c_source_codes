#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    char myStr[] = "4096 bytes should be enough";
    int pos = strspn(myStr, "0123456789");
    printf("%d\n", pos);
    pos = strcspn("hello world", "o");
    printf("%d\n", pos);
    return 0;
}
