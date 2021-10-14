N_ROWS = 6
N_COLS = 12
        .data
flag:
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
    .byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
        .text
main:

main__outer_init:
        li      $t0, 0
main__outer_cond:
        bge     $t0, 6, main__outer_after
        li      $t1, 0
main__inner_cond:
        bge     $t1, 12, main__inner_after

        # flag + sizeof(char) * (row * N_COLS + col)

        mul     $t2, $t0, N_COLS        # row * N_COLS
        add     $t2, $t2, $t1           # row * N_COLS + col
        lb      $a0, flag($t2)
        li      $v0, 11
        syscall
main__inner_step:
        add     $t1, $t1, 1
        j       main__inner_cond
main__inner_after:
        li      $v0, 11
        li      $a0, '\n'
        syscall
main__outer_step:
        add     $t0, $t0, 1
        j       main__outer_cond
main__outer_after:
        li      $v0, 0
        jr      $ra
