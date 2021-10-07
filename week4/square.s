# int main(void) {
#     int x, y;
#     printf("Enter a number: ");
#     scanf("%d", &x);
#     y = x * x;
#     printf("%d\n", y);
#     return 0;
# }

        .text
                                # x in $t0, y in $t1

        li      $v0, 4          # printf("Enter a number: ")
        la      $a0, prompt
        syscall

        li      $v0, 0          # return 0;
        jr      $ra             

        .data
prompt:
        .asciiz "Enter a number: "
