# Square a number in MIPS, with some checks.
# Abiram Nadarajah, October 2021
        
        .text
main:
                                                 # x in $t0, y in $t1

        li      $v0, 4                          # printf("Enter a number: ")
        la      $a0, prompt
        syscall

        li      $v0, 5                          # scanf("%d", &x)
        syscall
        move    $t0, $v0

        bgt     $t0, 46340, print_too_big       # if (x > 46340) goto print_too_big

        mul     $t1, $t0, $t0                   # y = x * x

        li      $v0, 1                          # printf("%d", y)
        move    $a0, $t1
        syscall

        li      $v0, 11                         # putchar('\n')
        li      $a0, '\n'
        syscall

        j       end

print_too_big:
        li      $v0, 4                          # printf("square too big for 32 bits\n")
        la      $a0, error_msg
        syscall

end:
        li      $v0, 0                          # return 0;
        jr      $ra      

        .data
prompt:
        .asciiz "Enter a number: "
error_msg:
        .asciiz "square too big for 32 bits\n"
