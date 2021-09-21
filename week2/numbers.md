# Numeric representation in C

This tutorial is somewhat content-heavy, so it typically tends to go a bit overtime.

## Working in other bases

### Q1: How can you tell if an integer constant in a C program is 
- decimal (base 10)     ``
- hexadecimal (base 16) ``
- octal (base 8)        ``
- binary (base 2) ...

How could we write a 

### How does hex work if we're out of digits?
```
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| DEC | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16|
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| HEX |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

### Q2: How would we represent these in binary, octal and hexadecimal?
* 1
* 8
* 10
* 15
* 16
* 100
* 127
* 200

## Bitwise operations

### Q3: Assume we have the following variables:
```c
uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;
```
What are the values of the following expressions? Give your answers in hexadecimal (although it's helpful to work in binary).

```
a = 
b =
c = 

a) a | b

b) a & b

c) a ^ b

d) a & ~b

e) c << 6

f) a >> 4

g) a & (b << 1)

h) b | c

i) a & ~c
```

### Q4: Consider a scenario where we have the following flags controlling access to a device.

```c
#define READING   0x01  // 
#define WRITING   0x02  // 
#define AS_BYTES  0x04  //
#define AS_BLOCKS 0x08  //
#define LOCKED    0x10  //
```

The flags are contained in an 8-bit register, defined as:
```c
unsigned char device;
```

Write C expressions to implement each of the following:

- mark the device as locked for reading bytes
```c
device = 
```
- mark the device as locked for writing blocks
```c
device = 
```
- set the device as locked, leaving other flags unchanged
```c
device = 
```
- remove the lock on a device, leaving other flags unchanged
```c
device =
```
- switch the device from reading to writing, leaving other flags unchanged
```c
device = 
```
- toggle the reading and writing flags, leaving other flags unchanged
```c
device = 
```

### Q6: Given the following type definition:
```c
typedef unsigned int Word;
```
Write a function 
```c
Word reverse_bits(Word w);
```

See `reverse_bits.c`.

## Lab notes
### sixteen_in
- You can use `char *bits` exactly like an array! For example, in
    ```bash
    $ ./sixteen_in 0101010101010101
    ```
    `bits[0]` is '0', `bits[1]` is 1, and so on. Importantly, `bits[16]` is the null terminator, '\0'.
- '0' is not the same as the number 0, and '1' is not the number 1. The former is an ASCII representation of a character.

### sixteen_out
- How much room will we need to malloc for our string? We may have 16 bits to represent as characters, but what else does every string contain at the end?

### bcd
See [my Discourse comment](https://discourse.cse.unsw.edu.au/21t3/comp1521/t/lab02-2-digit-bcd-value/703/2)
