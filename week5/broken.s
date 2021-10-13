        .text
main:
main__loop_init:
        li      $t0, 1
main__loop_cond:
        bgt     $t0, 5, main__loop_after

        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

main__loop_step:
        # add     $t0, $t0, 1
        j       main__loop_cond

main__loop_after:
        li      $v0, 0
        jr      $ra



