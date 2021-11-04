// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    }

    FILE *stream = fopen(argv[1], "r");

    if (stream == NULL) {
        // char *error_msg = strerror(errno);
        // fprintf(stderr, "%s :(\n", error_msg);
        perror(argv[1]);
    }

    int c;
    while ((c = fgetc(stream)) != '\n' && c != EOF) {
        putchar(c);
    }
    putchar('\n');


    return 0;
}
