#include <stdio.h>
#include <stdlib.h>

static const int HEADER_LEN = 3;
static const int FOOTER_LEN = 3;
static const char *header = "msg"; 
static const char *footer = "end"; 

void die_eof() {
    fprintf(stderr, "error: Unexpected EOF in msg\n");
    exit(1);
}

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

    // check if header is valid
    for (int i = 0; i < HEADER_LEN; i++) {
        int byte = fgetc(stream);
        if (byte == EOF) {
            die_eof();
        } else if (byte != header[i]) {
            fprintf(stderr, "Invalid header: expected 0x%x instead of 0x%x\n",
                header[i],
                byte
            );
            exit(1);
        }
    }

    // skip past the message
    int message_length = fgetc(stream);
    if (message_length == EOF) {
        die_eof();
    }
    fseek(stream, message_length, SEEK_CUR);

    // check if footer is valid
    for (int i = 0; i < FOOTER_LEN; i++) {
        int byte = fgetc(stream);
        if (byte == EOF) {
            die_eof();
        } else if (byte != footer[i]) {
            fprintf(stderr, "Invalid footer: expected 0x%x instead of 0x%x\n",
                footer[i],
                byte
            );
            exit(1);
        }
    }

    printf("Success! The msg file '%s' was valid!\n", argv[1]);
}
