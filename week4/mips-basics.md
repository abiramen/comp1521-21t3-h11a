# Welcome to MIPS!

## Poll: How are we feeling with MIPS?

## MIPS? mipsy? spim? qtspim? xspim??

- Instruction set on [course homepage](https://cgi.cse.unsw.edu.au/~cs1521/21T3/resources/spim-guide.html)

## What are registers?

| Number | Name | Use |
|--------|------|-----|
| $0     |      |     |
| $1     |      |     |
| $2     |      |     |
| $4     |      |     |
| $8     |      |     |
| $16    |      |     |
| $26    |      |     |
| $29    |      |     |
| $31    |      |     |

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
