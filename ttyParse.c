#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

/**
 * Evaluates the bits from a tty_nr and prints the values as "major_version minor_version"
 */
int main(int argc, char **argv)
{
    const int MIN_PROC_ID = 1; // Minimum linux process ID.
    const int MAX_PROC_ID = 32768; // Maximum default linux process ID.
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

    const int MINOR_UPPER_MASK = 0xFFF00000; // Minor higher device number is in bits 31 to 20.
    const int MINOR_LOWER_MASK = 0xFF; // Minor lower device number is in bits 7 to 0.
    const int MAJOR_MASK = 0xFF00; // Major device number is in bits 15 to 8.

    unsigned int minorUpperValue = argValue & MINOR_UPPER_MASK;
    unsigned int minorLowerValue = argValue & MINOR_LOWER_MASK;
    unsigned int minorValue = (minorUpperValue >> 12) | minorLowerValue;

    unsigned int majorValue = (argValue & MAJOR_MASK) >> 8;

    printf("%d %d\n", majorValue, minorValue);

    exit(0);

}
