        .text
main:
        # n is $t0, fac is $t1, i is $t2
        li      $v0, 4          # printf("n  = ");
        la      $a0, prompt
        syscall

        li      $v0, 5          # scanf("%d", &n);
        syscall
        move    $t0, $v0

        li      $t1, 1          # fac = 1
        li      $t2, 1          # i = 1

loop:
        bgt     $t2, $t0, end   # if (i > n) goto end;
        mul     $t1, $t1, $t2   # fac = fac * i;
        addi    $t2, $t2, 1     # i = i + 1;
        j       loop

end:
        li      $v0, 4          # printf("n! = ");
        la      $a0, format_result
        syscall

        li      $v0, 1          # printf("%d", fac);
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

        li      $v0, 0          # return 0
        jr      $ra


        .data
prompt:
        .asciiz "n  = "
format_result:
        .asciiz "n! = "
