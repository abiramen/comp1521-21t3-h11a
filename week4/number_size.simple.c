#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100) goto second_condition;

print_other:
    printf("small/big\n");
    goto end;

second_condition:
    if (x < 1000) goto print_medium;
    goto print_other;

print_medium:
    printf("medium\n");

end:
    return 0;
}
