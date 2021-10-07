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
        syscall
        # v0 now contains the scanned in number
        move    $t0, $v0

        bgt     $t0, 46340, print_too_big

        mul     $t1, $t0, $t0   # y = x * x

        li      $v0, 1
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        j       end

print_too_big:
        li      $v0, 4          # printf("square too big for 32 bits\n")
        la      $a0, error_msg
        syscall

end:
        li      $v0, 0          # return 0;
        jr      $ra      

        .data
prompt:
        .asciiz "Enter a number: "
error_msg:
        .asciiz "square too big for 32 bits\n"
