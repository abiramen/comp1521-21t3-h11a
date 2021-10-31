# More structs and MIPS functions

We'll get started in a few minutes - we'll hopefully finish within an hour so that you can ask any assignment questions during lab time.

## Give MIPS directives to represent the following variables
```c
int v0;
int v1 = 42;
char v2;
char v3 = 'a';
double v4;
int v5[20];
int v6[10][5];
struct { int x; int y; } v7;
struct { int x; int y; } v8[4];
struct { int x; int y; } *v9[4];
```

```s
    .data
v0: .space 4    # 0x1000 - 0x1003
v1: .word  42   # 0x1004 - 0x1007
v2: .space 1    # 0x1008
v3: .byte  'a'  # 0x1009
    .align 0    # 0x101a - 0x101b
v4: .space 8    # 0x101c - 0x1023
v5: .space 20 * 4 # 0x1024 - 0x1073
v6: .space 10 * 5 * 4
v7: .space 4    # int x
    .space 4    # int y
v8: .space 8 * 4
v9: .space 4 * 4
```



# Translate `max.c` and `sum.c`


## For each of these structs, what are the likely offsets for each field, and the total size of each struct?

```c
struct _coord {     // 0x1000
    double x;       // 0x1000 to 0x1007
    double y;       // 0x1008 to 0x101f
};  // 16 bytes

typedef struct _node Node;
struct _node {      // 0x1000
    int value;      // 0x1000 to 0x1003
    Node *next;     // 0x1004 to 0x1007
}; // 8 bytes

struct _enrolment { // 0x1000
    int stu_id;         // e.g. 5012345     0x1000 to 0x1003
    char course[9]:     // e.g. "COMP1521"  0x1004 to 0x100c
    char term[5];       // e.g. "17s2"      0x100d to 0x1011
    char grade[3];      // e.g. "HD"        0x1012 to 0x1014
    // 3 bytes of padding                   0x1015 to 0x1017
    double mark;        // e.g. 87.3        0x1018 to 0x101f
} e; // 32 bytes


```s
    .data
e:  .space 32
# e.stu_id
    lw  $t0, e
# e.course[0]
    la  $t1, e
    lb  $t2, 4($t1)
# OR
    li  $t1, 4
    lb  $t2, 4($t1)
```

struct _queue {
    int nitems;     // # items currently in queue
    int head;       // index of oldest item added
    int tail;       // index of most recent item added
    int maxitems;   // size of array
    Item *items;    // malloc'd array of Items
};
```
