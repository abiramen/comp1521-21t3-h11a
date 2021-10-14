        .data
numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

        .text
main:

main__loop_init:
        li      $t0, 0
main__loop_cond:
        bge     $t0, 5, main__loop_after
        mul     $t1, $t0, 4
        lw      $t2, numbers($t1)

        li      $t3, 9
        sub     $t4, $t3, $t0
        mul     $t4, $t4, 4
        lw      $t3, numbers($t4)

        sw      $t2, numbers($t4)
        sw      $t3, numbers($t1)

        add     $t0, $t0, 1
        j       main__loop_cond
main__loop_after:
        li      $v0, 0
        jr      $ra
