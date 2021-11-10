#include <stdio.h>

static const int HEADER_LEN = 3;
static const int FOOTER_LEN = 3;
static const char *header = "msg"; 
static const char *footer = "end"; 

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    // TODO: check if the message file is valid.

}
