# Welcome to COMP1521!

### Poll: What course did you take before coming to 1521?

## Introductions 👋
Feel free to introduce yourself!
- preferred name (and pronouns)
- what degree you're doing 🎓
- either show and tell something interesting you've got in your room OR
- what is your favourite ice cream flavour? 🍦

Webcams are optional, but it'd be cool if you could turn it on 🎉

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
    // local:
    // global:
    int c, d;
    ...
}

double e;

int fun2() {
    // local:
    // global:
    int f;
    static int ff;
    ...
    fun1();
    ...
}

int g;

int main(void) {
    // local:
    // global:
    char h[10];
    int i;
    ...
    fun2()
    ...
}
```
#### Consider what happens during the execution of this program and answer the following.
- Which variables are accsessible from within `main()`
- Which variables are accessible from within `fun2()`?
- Which variables are accessible from within `fun1()`?
- Which variables are removed when `fun1()` returns?
- Which variables are removed when `fun2()` returns?
- How long does the variable `f` exist during program execution?
- How long does the variable `g` exit during program execution?

What's `static`??? See `counter.c`.

### Q3: Explain the differences between the properties of the variables `s1` and `s2` in the following program fragment. Where is each variable in memory?
```c
#include <stdio.h>

char *s1 = "abc";

int main(void) {
    char *s2 = "def";
    // ...
}
```

### Q4: C's sizeof operator is a unary operator (has 1 operand) - what are examples of other C unary operators?
```c
```
### Q5: Why is C's sizeof operator different to C's other operators?

### Q6: Discuss errors in this code:
```c
    struct node *a = NULL:
    struct node *b = malloc(sizeof b);
    struct node *c = malloc(sizeof struct node);
    struct node *d = malloc(8);
    c = a;
    d.data = 42;
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
7. 
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
