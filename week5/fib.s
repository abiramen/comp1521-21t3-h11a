########################################################
        .data
enter_number:
        .asciiz "Enter a number: "
fib_out_1:
        .asciiz "Fibonacci of "
fib_out_2:
        .asciiz " is "
########################################################
# .text <main>
        .text
main:
#
# Stack: $ra, [...]
# Uses: $a0, $t0
# Clobbers: $t0, $a0
#
# Local:
#       - $t0: int n
# Structure:
# -> main
#       -> pro
#       -> body
#       -> epi
# Returns:
#       - $v0: exit status

# Stack: Refers to any values we save on the stack, in order
# Uses: Any registers used by our function (excluding $v0)
# Clobbers: Any registers we destroy (generally, clobbers = uses - stack)
# Args: Any arguments needed by the function
# Local: Registers which continually represent some value within the function

main__pro:
        add     $sp, $sp, -4
        sw      $ra, 0($sp)
main__body:
        li      $v0, 4                  # printf("Enter a number: ");
        la      $a0, enter_number
        syscall

        li      $v0, 5                  # scanf("%d", &n);
        syscall
        move    $t0, $v0

        li      $v0, 4                  # printf("Fibonacci of ");
        la      $a0, fib_out_1
        syscall

        li      $v0, 1
        move    $a0, $t0
        syscall

        li      $v0, 4                  # printf("is ");
        la      $a0, fib_out_2
        syscall

        # TODO: call fib and put its result in $a0
        # jal is the same as j
        # but it sets $ra to point
        # to the next instruction

        # Conventions:
        # We place arguments in the $a registers
        # Functions place their return value in $v0
        # A function needs to return the stack pointer to
        # its original value
        # We MUST assume that calling a function destroys
        # any values inside $t registers
        # We MUST also assume that calling a function destroys
        # any values inside $a registers
        # If we overwrite an $s register, we MUST
        # return it to its original value

        move    $a0, $t0                # calls fib(n)
        jal     fib

        move    $a0, $v0
        li      $v0, 1                  # printf("%d", fib(n))
        syscall

        li      $v0, 11                 # putchar('\n')
        li      $a0, '\n'
        syscall

main__epi:
        li      $v0, 0                  # return 0;
        lw      $ra, 0($sp)
        add     $sp, $sp, 4
        jr      $ra

########################################################
# .text <fib>
        .text
fib:
#
# Args:
#       - $a0: int n
#
# Stack: $ra, $s0, $s1, [...]
# Uses: $a0
# Clobbers: $a0
#
# Local:
#       - $s0: int n
#       - $s1: fib(n - 1)
#
# Structure:
# -> fib
#       -> pro
#       -> body
#               -> n_lt_2
#               -> n_ge_2
#       -> epi
# Returns:
#       - $v0: result
fib__pro:
        add     $sp, $sp, -12
        sw      $s1, 0($sp)
        sw      $s0, 4($sp)
        sw      $ra, 8($sp)
fib__body:
        blt     $a0, 2, fib__n_lt_2
fib__n_ge_2:
        move    $s0, $a0        # Save n

        add     $a0, $s0, -1    # call fib(n - 1)
        jal     fib
        move    $s1, $v0

        add     $a0, $s0, -2    # call fib(n-2)
        jal     fib

        add     $v0, $v0, $s1   # return fib(n-2) + fib(n-1)
        j       fib__epi
fib__n_lt_2:
        move    $v0, $a0
fib__epi:               # Function epilogue
        lw      $ra, 8($sp)
        lw      $s0, 4($sp)
        lw      $s1, 0($sp)
        add     $sp, $sp, 12
        jr      $ra
