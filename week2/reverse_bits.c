#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

// TODO
Word reverse_bits(Word w) {

    int n_bits = sizeof(Word) * 8;
    Word ret = 0;

    for (int i = 0; i < n_bits; i++) {
        Word read_mask = 1u << (n_bits - 1 - i);
        Word write_mask = 1u << i;

        if (w & read_mask) {
            ret |= write_mask;
        }
    }
    return ret;
}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
