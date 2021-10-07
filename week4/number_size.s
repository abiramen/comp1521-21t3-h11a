# Determine if a number is within a range.
# Abiram Nadarajah, October 2021

        .text
main:
        # x is $t0
        li      $v0, 4                          # printf("Enter a number: ")
        la      $a0, prompt
        syscall

        li      $v0, 5                          # scanf("%d", &x)
        syscall
        move    $t0, $v0

        bgt     $t0, 100, second_condition      # if (x > 100) goto second_condition

print_other:
        li      $v0, 4                          # printf("small/big\n")
        la      $a0, other_msg
        syscall

        j       end

second_condition:
        blt     $t0, 1000, print_medium         # if (x < 1000) goto print_medium
        j       print_other

print_medium:
        li      $v0, 4                          # printf("medium\n");
        la      $a0, medium_msg
        syscall

end:
        li      $v0, 0                          # return 0
        jr      $ra

        .data
prompt:
        .asciiz "Enter a number: "
other_msg:
        .asciiz "small/big\n"
medium_msg:
        .asciiz "medium\n"
