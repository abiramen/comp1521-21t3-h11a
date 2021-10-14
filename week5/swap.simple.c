#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

    i = 0;
main__loop_cond:
    if (i >= 5) goto main__loop_after;
    int x = numbers[i];
    int y = numbers[9 - i];
    numbers[i] = y;
    numbers[9 - i] = x;
    i++;
    goto main__loop_cond;
main__loop_after:
    return 0;
}
