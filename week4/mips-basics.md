# Welcome to MIPS!

## Poll: How are we feeling with MIPS?

## MIPS? mipsy? spim? qtspim? xspim??
- MIPS is the name of a CPU architecture
    - instruction sets which define what the CPU can do
- we can use emulators to simulate running MIPS instructions on other architectures
    - emulators provide us with some extra 'instructions' which don't actually exist on MIPS
        - these 'pseudoinstructions' get converted into real MIPS instructions
    - mipsy
        - helpful error messages
        - it might have some bugs
    - spim
        - been around for years
        - autotest/automark will use spim for marking
        - qtspim and xspim
            - visual interface (over VLAB)


- Instruction set on [course homepage](https://cgi.cse.unsw.edu.au/~cs1521/21T3/resources/spim-guide.html)

## What are registers?
- computers have a hierarchy of memory
    - registers (fastest)
        - costs more, so we don't have many
        - MIPS gives us 32 general purpose registers
        - on MIPS32, registers are 32 bits
    - RAM (computer memory sticks)
        - relatively fast
        - typically have a few gigabytes
    - Solid State Drives
    - Hard Drives

| Number | Name | Use |
|--------|------|-----|
| $0     | $zero| Always contains the value zero, no matter what we do to it    |
| $1     | $at  | Assembler temporary registers - used by assemblers like those in SPIM and mipsy to provide pseudoinstructions  |
| $2     | $v0  | Return values from functions, including syscalls    |
| $4     | $a0 | How we pass an argument to a function such as a syscall    |
| $8     | $t0  | Temporary registers - we can use these however we want    |
| $16    | $s0  | 'Saved' registers - useful when we use functions    |
| $26    | $k0     | kernel register - avoid using    |
| $29    | $sp   | stack pointer - keeps track of the top of our stack - useful when we do functions   |
| $31    | $ra    | return address specifies where the program should go once a function is finished executing    |

- the kernel refers to the 'core' of the operating system
    - this core can perform privileged tasks
    - user programs are restricted in what they can do
        - for example, we can't access memory from other programs

## Translate the following code to MIPS.
```c
// print the square of a number
#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);
    y = x * x;
    printf("%d\n", y);
    return 0;
}
```

See `square.s`.

## Translate this C program to simplified C, and then translate it to MIPS assembler.

```c
#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 46340) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    }
    return 0;
}
```
See `square_max.simple.c` and `square_max.s`.


## Translate this C program to simplified C, and then translate it to MIPS assembler.

```c
#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) {
        printf("medium\n");
    } else {
        printf("small/big\n");
    }
}
```

See `number_size.simple.c` and `number_size.s`.

## Translate this C program to simplified C, and then translate it to MIPS assembler.

```c
#include <stdio.h>

int main(void) {
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n",x);
    }
}
```

## Translate this C program to simplified C, then translate it to MIPS assembler.

```c
// Simple factorial calculator  - without error checking

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }

    printf ("n! = %d\n", fac);
    return 0;
}
```
