        .data
array:
        .word   1, 2, 4, 2, 3, 1
# If your function modifies the stack pointer,
# you must return it to its original value

################################################################################
# .text <main>
#
# Frame:        $ra
# Uses:         $ra, $a0, $a1, $v0
# Clobbers:     $a0, $a1, $v0
#
# Structure:
# -> main
#       -> [prologue]
#       -> [body]
#       -> [epilogue]

        .text
main:
main__prologue:
        addi    $sp, $sp, -4
        sw      $ra, 0($sp)

main__body:

        # formula for finding address of array[i]
        # array + sizeof(element) * i
        # array + 4 * i

        la      $a0, array
        li      $a1, 6

        jal     max

        move    $a0, $v0
        li      $v0, 1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        syscall

main__epilogue:
        li      $v0, 0

        lw      $ra, 0($sp)
        addi    $sp, $sp, 4

        jr      $ra

################################################################################
# .text <max>
        .text
max:
#
# Frame:        $ra, $s0
# Uses:         $ra, $s0, $a0, $a1, $t0, $v0
# Clobbers:     $a0, $a1, $t0, $v0
# 
# Locals:
#       - $s0: int first_element
#       - $t0: int curr_max
#
# Args:
#       - $a0: int a[]
#       - $a1: int length
#
# Structure:
#       -> [prologue]
#       -> [body]
#               -> ret_curr_max
#               -> first_el_gt_curr
#               -> base
#       -> [epilogue]
#
# Returns:
#       - $v0: int max 


max__prologue:
        addi    $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $s0, 4($sp)

max__body:
        lw      $s0, ($a0)              # first_element = a[0]
        beq     $a1, 1, max__base       # if (length == 1) goto max__base;

        addi    $a0, $a0, 4
        addi    $a1, $a1, -1

        jal     max
        move    $t0, $v0                # curr_max = max(...)

        bgt     $s0, $t0, max__first_el_gt_curr

max__ret_curr_max:
        move    $v0, $t0
        j       max__epilogue

max__first_el_gt_curr:
        move    $t0, $s0
        j       max__ret_curr_max

max__base:
        move    $v0, $s0                # retval = first_element

max__epilogue:
        lw      $s0, 4($sp)
        lw      $ra, 0($sp)
        addi    $sp, $sp, 8

        jr      $ra
