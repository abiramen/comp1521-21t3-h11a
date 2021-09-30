#include <stdio.h>
#include <stdint.h>

typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;

/* 
For example:
00000000 00000101 01000000 01110110 
                           00111111
                            3   f

middle six bits are 101010
 lower six bits are 110110  
*/

// TODO
six_bit_groups_t get_bit_groups(uint32_t value) {
    six_bit_groups_t result;
    uint32_t mask = 0x3f;
    result.lower_bits = value & mask;
    result.middle_bits = (value >> 13) & mask;

    return result;
}

int main(void) {
    return 0;
}
