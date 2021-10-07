# Count by threes within a range using a loop.
# Abiram Nadarajah, October 2021

        .text
main:
        li      $t0, 24         # int x = 24

loop:
        bge     $t0, 42, end    # if (x >= 42) goto end

        li      $v0, 1          # printf("%d\n",x)
        move    $a0, $t0
        syscall

        li      $v0, 11         # putchar('\n')
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 3     # x = x + 3
        j       loop

end:
        li      $v0, 0          # return 0
        jr      $ra
