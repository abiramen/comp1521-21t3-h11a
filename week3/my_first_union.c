#include <stdio.h>

union my_first_union {
    int value;
    char str[4];
};

int main(void) {
    union my_first_union a;
    
    a.value = 0x00657942;

    printf("reading the union as an int: %8x\n", a.value);
    printf("reading the union as a string: %s\n", a.str);
}
