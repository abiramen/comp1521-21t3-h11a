// Simple factorial calculator  - without error checking

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;

    int i = 1;

loop:
    if (i > n) goto end;
    fac = fac * i;
    i = i + 1;
    goto loop;

end:
    printf("n! = ");
    printf("%d", fac);
    putchar('\n');
    return 0;
}
