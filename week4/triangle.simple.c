// print a triangle
#include <stdio.h>

int main(void) {
    int i = 0;
main__row_loop:
    if (i > 10) goto main__end;
    int j = 0;
main__inner_loop:
    if (j >= i) goto main__inner_loop_done;
    putchar('*');
    j = j + 1;
    goto main__inner_loop;
main__inner_loop_done:
    putchar('\n');
    i = i + 1;
    goto main__row_loop;
main__end:
    return 0;
}

/*
    // Converting to while loops first:
    int main(void) {
        int i = 0;
        while (i <= 10) {
            int j = 0;
            while (j < i) {
                printf("*");
                j++;
            }
            printf("\n");
            i++
        };
        return 0;
    }
*/
