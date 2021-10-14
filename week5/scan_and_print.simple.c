#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

    i = 0;
main__loop1_cond:
    if (i >= 10) goto main__loop1_after;
    scanf("%d", &numbers[i]);
main__loop1_step:
    i++;
    goto main__loop1_cond;
main__loop1_after:

    i = 0;
main__loop2_cond:
    if (i >= 10) goto main__loop2_after;
    printf("%d", numbers[i]);
    putchar(' ');
main__loop2_step:
    i++;
    goto main__loop2_cond;
main__loop2_after:
    return 0;
}

