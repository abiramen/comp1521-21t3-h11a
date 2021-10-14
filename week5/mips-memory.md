# Week 5 - MIPS Memory

We'll get started in a few minutes!

Today:
- MIPS memory
- 1D arrays
- 2D arrays
- Quick overview of functions (maybe - we'll cover it again in Week 7, but this is handy for the assignment)

We'll take a few breaks throughout, since there is a fair amount of content.

## Debugging
- `1521 mipsy` is your best friend
    - *load* (l), *help* (h), *decompile* (d), *breakpoint* (br i), *step* (s), *print* (p), *step2syscall* (s2s)
- qtspim and spim also have some debugging
- could also add some 'printf' statements to check what values are
    - (except we don't actually have printf, so you'll be using syscalls)
- See `broken.s`.

## Do-while loops? How do we translate a do-while loop to MIPS?

- A do-while loop is basically a while loop.
    - The do-while loop definitely runs at least once.

See `do_while.c`, `do_while.simple.c`, and `do_while.s`.

## MIPS memory directives
Assume that the data segment of the following program starts at address 0x10000020.
```s
    .data
a:  .word   42
b:  .space  4
c:  .asciiz "abcde"
    .align  2
d:  .byte   1, 2, 3, 4
e:  .word   1, 2, 3, 4
f:  .space  1
```
See [the following spreadsheet](https://docs.google.com/spreadsheets/d/1lBBzlFn9D_J4_pRME4HgV_MTR9fdGUzz6vioxOSBh2Q/edit?usp=sharing).

## C to MIPS memory directives
Convert the following into MIPS memory directives:
```c
int u;
int v = 42;
char w;
char x = 'a';
double y;
int z[20];
```

```s
    .data
u: .space 4
v: .word 42
w: .space 1
x: .byte 'a'
   .align 2
y: .space 8
z: .space 4 * 20
```

## Array memory layout
See `1d.c`.

## Translate the following C code to MIPS.

```c
#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

    i = 0;
    while (i < 10) {
        scanf("%d", &numbers[i]);
        i++;
    }

    i = 0;
    while (i < 10) {
        printf("%d ", numbers[i]);
        i++;
    }
}
```

See `scan_and_print.c`, `scan_and_print.simple.c` and `scan_and_print.s`.

## Translate the following C code to MIPS.

```c
int main(void) {
    int i;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

    i = 0;
    while (i < 5) {
        int x = numbers[i];
        int y = numbers[9 - i];
        numbers[i] = y;
        numbers[9 - i] = x;
        i++;
    }
}
```
See `swap.c`, `swap.simple.c` and `swap.s`.

## 2D arrays
See `flag.c` and `flag.s`.

## Functions
Back at 12:45 :)
See `fib.c`, `fib.simple.s` and `fib.s`.
