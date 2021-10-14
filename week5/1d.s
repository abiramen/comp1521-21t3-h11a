N_ELEMENTS = 5

        .data
array:
        .word 3, 1, 4, 1, 5

        .text
main:

main__loop_init:
        li      $t0, 0

main__loop_cond:
        bge     $t0, N_ELEMENTS, main__loop_after
        mul     $t1, $t0, 4     # $t1 = $t0 * 4
        lw      $a0, array($t1) # array + $t0 * 4
        li      $v0, 1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        add     $t0, $t0, 1
        j       main__loop_cond

main__loop_after:
        li      $v0, 0
        jr      $ra
        

