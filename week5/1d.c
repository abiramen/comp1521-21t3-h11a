#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

// main__loop_init:
    int i = 0;
main__loop_cond:
    if (i >= N_ELEMENTS) goto main__loop_after;
    printf("%p: ", &array[i]);
    printf("%d", array[i]);
    putchar('\n');
    i++;
    goto main__loop_cond;
main__loop_after:
    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

