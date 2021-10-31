#include <stdio.h>

struct _enrolment { // 0x1000
    int stu_id;        
    char course[9];     // e.g. "COMP1521"  0x1004 to 0x100c
    char term[5];       // e.g. "17s2"      0x100d to 0x1011
    char grade[3];      // e.g. "HD"        0x1012 to 0x1014
    // 3 bytes of padding                   0x1015 to 0x1017
    double mark;        // e.g. 87.3        0x1018 to 0x101f
};

int main(void) {
    // gcc sizeof.c -o sizeof -m32 for a 32 bit system
    printf("%zu\n", sizeof(struct _enrolment));

    return 0;
}
