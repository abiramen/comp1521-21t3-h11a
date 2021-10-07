# int main(void) {
#     int x, y;
#     printf("Enter a number: ");
#     scanf("%d", &x);
#     y = x * x;
#     printf("%d\n", y);
#     return 0;
# }

        .text
main:
                                # x in $t0, y in $t1

        li      $v0, 4          # printf("Enter a number: ")
        la      $a0, prompt
        syscall

        li      $v0, 5          # scanf("%d", &x)
        syscall                 # note: $v0 now contains the scanned in number
        move    $t0, $v0

        mul     $t1, $t0, $t0   # y = x * x

        li      $v0, 1          # printf("%d", y);
        move    $a0, $t1
        syscall

        li      $v0, 11         # putchar('\n')
        li      $a0, '\n'
        syscall

        li      $v0, 0          # return 0;
        jr      $ra      

        .data
prompt:
        .asciiz "Enter a number: "
