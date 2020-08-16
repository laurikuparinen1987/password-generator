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
    long l;         // Lenght of no-special-character password

    // Parse flags
    int opt;
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
        case 's':
            l = strtol(argv[2], NULL, 0);
            //printf("\nargv[2] in long int=%ld",l);
            break;

        default: /* '?' */
            fprintf(stderr, "Usage: passworgenerator [-s] [passwordlength]\n");
            exit(EXIT_FAILURE);
        }
    }

    // Parse pw length
    for (j = 0; j < argc; j++) {   // Loop through cmd parameters
        param = atoi(argv[1]);
    }

    if (param > 4) {    // if any of the parameters is higher than 4 (minimum lenght for password)...
        len = param;    // ...that is the new lenght of password
    }

    // Randomizer routine
    const char* groups[] = {
        "1234567890",  // numbers
        "abcdefghijklmnoqprstuvwyzx",  // lowercase
        "ABCDEFGHIJKLMNOQPRSTUYWVZX",  // uppercase
        "!@#$%^&*(){}[]:<>?,./",    // symbols
    };

    const char* nsc_groups[] = {
        "1234567890",  // numbers
        "abcdefghijklmnoqprstuvwyzx",  // lowercase
        "ABCDEFGHIJKLMNOQPRSTUYWVZX",  // uppercase
    };

    if (l > 0) {       // No special characters
        const size_t numGroups_nsc = sizeof(nsc_groups)/sizeof(nsc_groups[0]);
        srand((unsigned int)(time(NULL)));

        // only proceed if we got a number
        for ( ; len; --len) {
            unsigned group_nsc = rand_lim(numGroups_nsc-1);
            putchar(picker(nsc_groups[nsc_groups]));
        }
        putchar('\n');
    }
    else {          // Special characters enabled
        const size_t numGroups = sizeof(groups)/sizeof(groups[0]);
        srand((unsigned int)(time(NULL)));

        // only proceed if we got a number
        for ( ; len; --len) {
            unsigned group = rand_lim(numGroups-1);
            putchar(picker(groups[group]));
        }
        putchar('\n');
    }
}
