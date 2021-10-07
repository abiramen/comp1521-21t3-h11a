        .text
main:
        li      $t0, 0                          # int i = 0;
main__row_loop:
        bgt     $t0, 10, main__end              # if (i > 10) goto main__end;

        li      $t1, 0                          # int j = 0;
main__inner_loop:
        bge     $t1, $t0, main__inner_loop_done # if (j >= i) goto main__inner_loop_done;

        li      $v0, 11                         # putchar('*');
        li      $a0, '*'
        syscall

        add     $t1, $t1, 1                     # j = j + 1;
        j       main__inner_loop

main__inner_loop_done:
        li      $v0, 11                         # putchar('\n');
        li      $a0, '\n'
        syscall

        add     $t0, $t0, 1                     # i = i + 1
        j       main__row_loop

main__end:
        li      $v0, 0                          # return 0;
        jr      $ra


