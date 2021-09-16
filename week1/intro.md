# Welcome to COMP1521!

### Poll: What course did you take before coming to 1521?

## Introductions 👋
Feel free to introduce yourself!
- preferred name (and pronouns)
- what degree you're doing 🎓
- either show and tell something interesting you've got in your room OR
- what is your favourite ice cream flavour? 🍦

Webcams are optional, but it'd be cool if you could turn it on 🎉

## Blackboard Collaborate and IKEA furniture

## Where to find course resources 📜
- Forum
- Tutorial recordings
- Course content
- Tutorial resources and feedback

## C revision

### Q2: Consider the following C program skeleton. 
```c
int  a;
char b[100];

int fun1() {
    // local: c, d
    // global: a, b
    int c, d;
    ...
}

double e;

int fun2() {
    // local: f, ff
    // global: a, b, e (g is not, as it is defined after)
    int f;
    static int ff;
    ...
    fun1();
    ...
}

int g;

int main(void) {
    // local: h, i
    // global: a, b, e, g
    char h[10];
    int i;
    ...
    fun2()
    ...
}
```
#### Consider what happens during the execution of this program and answer the following.
- Which variables are accessible from within `main()`
- Which variables are accessible from within `fun2()`?
- Which variables are accessible from within `fun1()`?
- Which variables are removed when `fun1()` returns? c, d
- Which variables are removed when `fun2()` returns? f
- How long does the variable `f` exist during program execution? only while `fun2()` is running.
- How long does the variable `g` exist during program execution? for the lifetime of the whole program

What's `static`??? See `static.c`.

### Q3: Explain the differences between the properties of the variables `s1` and `s2` in the following program fragment. Where is each variable in memory?
```c
#include <stdio.h>

// global variable:
char *s1 = "abc";

int main(void) {
    // local to main:
    char *s2 = "def";
    s1 = "ghi";
    // ...
}
```

### Q4: C's sizeof operator is a unary operator (has 1 operand) - what are examples of other C unary operators?
```c
struct node {
    int val;
    struct node *next;
}

int count(int n) {

}

int main(void) {
    int w;
    // sizeof can be used on types and variable names
    printf("%zu", sizeof(w)); // calculated at compile time
    int a = 0;
    a++; // a = a + 1;
    ++a;
    a--; // a = a - 1;
    --a;

    // bitwise NOT
    int b = ~a;

    // logical NOT flips a condition
    int c = 7;
    if (!(false)) {
        // !false = true
        // !true = false
    }

    int d = 0;
    // address of operator
    int *ptr = &d;

    // dereference operator - it follows a pointer
    *ptr = 2;

}

```
### Q5: Why is C's sizeof operator different to C's other operators?
- types only exist at compile time
- they do not exist in machine code
    - machine code is compiled code for the CPU to run

### Q6: Discuss errors in this code:
```c
    struct node *a = NULL: // should be a semicolon
    struct node *b = malloc(sizeof b); // b has the type of a pointer
    // sizeof b is going to give us the size of a pointer, not a struct node
    // malloc(sizeof *b)
    struct node *c = malloc(sizeof(struct node));
    // when using sizeof on a type, make sure to have brackets
    struct node *d = malloc(8);
    // we should use sizeof to get the size of the struct instead of assuming 8
    c = a; // memory leak - no longer know where c used to point to
    d.data = 42; // this should be (*d).data = 42;

    // this is equivalent to (*d).data = 42;
    d->data = 42;

    // NULL pointer dereference - c is a NULL pointer, so we can't follow it - segmentation fault
    c->data = 42;

```

### In which Abiram goes on his usual `man` page tangent.
`man` is our best friend this term!
#### man page sections:
<p>
1. programs and shell commands<br>
2. system calls (more on this later)<br>
3. C library calls (very handy this week!)<br>
...<br>
7. miscellaneous
</p>

#### `man -k`:
allows us to search pages

### Poll: how familiar are you with for loops?
for loops are really just spicy while loops. See `for.c`

### Q7: How familiar are you with pointers? What is a pointer? How do pointers relate to other variables?

### What is recursion? How would we implement factorial using recursion?
See `factorial.c`

### Consider the following C program. How would we rewrite this as a recursive program?
```c
#include <stdio.h>

int main(void) {
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}
```

See `print_array.c`

## Lab notes

### no_vowels
The challenge description provides some subtle hints:
- scanf to **one character at a time** from stdin.
- printf to print **one character at a time** to stdout.
- we DON'T need to work with strings here
- we only need space to store one character
### fibonacci
This challenge says you need to implement it recursively, but also mentions something called **memoization**, which might look a bit confusing at first.

My advice would be to try solve the lab exercise without memoization first, just to get it working, before attempting a memoized solution - if you're confused by the memoization part, feel free to ask us!
