#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int rand_lim(int limit) {
    /* return a random number between 0 and limit inclusive. */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do {
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

char picker(const char *charset) {
    return charset[rand_lim(strlen(charset)-1)];
}

void main(int argc, char **argv)
{
    int len = 8;    // Default lenght for password
    int param, i, j;

    for (j = 0; j < argc; j++) {   // Loop through cmd parameters
        param = atoi(argv[j]);
    }

    if (param > 4) {    // if any of the parameters is higher than 4 (minimum lenght for password)...
        len = param;    // ...that is the new lenght of password
    }

    // Randomizer routine
    const char* groups[] = {
        "1234567890",  // numbers
        "abcdefghijklmnoqprstuvwyzx",  // lowercase
        "ABCDEFGHIJKLMNOQPRSTUYWVZX",  // uppercase
        "!@#$₤£€%^ˇ&*(){}[]:<>?,./|\\.=",    // symbols
    };
    const size_t numGroups = sizeof(groups)/sizeof(groups[0]);
    srand((unsigned int)(time(NULL)));

    // only proceed if we got a number
    for ( ; len; --len) {
        unsigned group = rand_lim(numGroups-1);
        putchar(picker(groups[group]));
    }
    putchar('\n');

}
