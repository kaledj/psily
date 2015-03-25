#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <unistd.h>

/**
 * Parses the time from the /proc/<id>/stat file.
 */
int main(int argc, char **argv)
{
    const int BASE = 10; // Sets the base to interpret the process ID in.

    if(argc != 2)
    {
        printf("Wrong number of arguments!\n");
        exit(0);
    }

    int argValue;
    char *end;

    argValue = strtol(argv[1], &end, BASE);
    if(errno == ERANGE)
    {
        printf("Range error!");
        exit(1);
    }

    printf("%ld\n", argValue/sysconf(_SC_CLK_TCK) );

    exit(0);

}
