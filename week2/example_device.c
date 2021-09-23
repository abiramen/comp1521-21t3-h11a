#include <stdio.h>

int main(void) {
    // reading
    // writing
    // as_bytes
    // as_blocks
    // locked


    // integer variables are (usually) 4 bytes
    // there are 8 bits/byte
    // 4 * 8 = 32 bits

    unsigned char device; // 8 bits
                          // bit 0: always 0
                          // bit 1: always 0
                          // bit 2: always 0
                          // bit 3: locked
                          // bit 4: as_blocks
                          // bit 5: as_bytes
                          // bit 6: writing
                          // bit 7: reading


    int reading = 1; // reading is true
    int writing = 0; // writing is false
    int as_bytes = 1;
    int as_blocks = 0;
    int locked = 1;

    if (reading) {
        printf("we can read!\n");
    }

    if (!writing) {
        printf("we can't write!\n");
    }

}
