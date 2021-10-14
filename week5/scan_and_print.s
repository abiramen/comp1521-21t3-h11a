        .data
numbers:
        .word 0:10

        .text
main:

main__loop1_init:
        li      $t0, 0
main__loop1_cond:
        bge     $t0, 10, main__loop1_after
        
        li      $v0, 5
        syscall

        # &numbers[i] = numbers + 4 * i
        mul     $t1, $t0, 4
        sw      $v0, numbers($t1)
main__loop1_step:
        add     $t0, $t0, 1
        j       main__loop1_cond

main__loop1_after:

main__loop2_init:
        li      $t0, 0
main__loop2_cond:
        bge     $t0, 10, main__loop2_after

        mul     $t1, $t0, 4
        lw      $a0, numbers($t1)
        li      $v0, 1
        syscall

        li      $v0, 11
        li      $a0, ' '
        syscall

main__loop2_step:
        add     $t0, $t0, 1
        j       main__loop2_cond
main__loop2_after:
        li      $v0, 0
        jr      $ra

