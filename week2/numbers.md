# Numeric representation in C

This tutorial is somewhat content-heavy, so it typically tends to go a bit overtime.

## Working in other bases

### Q1: How can you tell if an integer constant in a C program is 
- decimal (base 10)     `21`         -> 0 to 9
- hexadecimal (base 16) `0x15`      
- octal (base 8)        `025`        -> 0 to 8
- binary (base 2) ...   `0b00010101` -> 0 and 1
    - not yet implemented in the C standard
    - gcc/dcc will let you do this -> don't use it however


### How does hex work if we're out of digits?
```
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| DEC | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15|
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| HEX | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F |
+-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

### Q2: How would we represent these in binary (8 bits), hexadecimal (2 digits) and octal (3 dig?
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
a = 0101010101010101
b = 1010101010101010
c = 0000000000000001

a) a | b  (bitwise OR operator -> if any bit in a column is set, then the resulting bit is set)
    a
    b
a | b

b) a & b  (bitwise AND -> if both bits in a column are set, then the result is set)
    a
    b
a & b

c) a ^ b  (bitwise XOR -> exclusive OR -> if exactly one bit in a column is set, then the result is set)
    a
    b
a | b

d) a & ~b  (bitwise NOT / inversion / bit negation) -> flips every bit (ie 0 becomes 1, 1 becomes 0)
(a AND (NOT b))

e) c << 6  (bitwise left shift)

f) a >> 4  (bitwise right shift)

g) a & (b << 1)

h) b | c

i) a & ~c
```

### Q4: Consider a scenario where we have the following flags controlling access to a device.

```c


unsigned char device; // 8 bits
                      // bit 0: always 0
                      // bit 1: always 0
                      // bit 2: always 0
                      // bit 3: locked
                      // bit 4: as_blocks
                      // bit 5: as_bytes
                      // bit 6: writing
                      // bit 7: reading

#define READING   0x01  // binary: 0000 0001
#define WRITING   0x02  // binary: 0000 0010
#define AS_BYTES  0x04  // binary: 0000 0100
#define AS_BLOCKS 0x08  // binary: 0000 1000
#define LOCKED    0x10  // binary: 0001 0000

```

Write C expressions to implement each of the following:

- mark the device as locked for reading bytes
```c

result should look like 0001 0101
  LOCKED 0001 0000
AS_BYTES 0000 0100
 READING 0000 0001

         0001 0101
device = LOCKED | AS_BYTES | READING;
```
- mark the device as locked for writing blocks
```c
result should look like 0001 1010
device = LOCKED | AS_BLOCKS | WRITING;
```
- set the device as locked, leaving other flags unchanged
```c
device = device | LOCKED;
device |= LOCKED
```

```c
Example: device is initially 0000 1001

initial 0000 1001 |
 LOCKED 0001 0000

 device 0001 1001
```

- remove the lock on a device, leaving other flags unchanged
```c
device = device & ~LOCKED;
device &= ~LOCKED;
```

```c
Example: device is initially 0001 1001

initial  0001 1001 &
~LOCKED  1110 1111

device   0000 1001
 LOCKED  0001 0000


```
- switch the device from reading to writing, leaving other flags unchanged
    - remove reading
    - add writing
```c
device = device & ~READING) | WRITING;
```

``` c
Example: device is initially 0001 0001

 initial 0001 0001 &
~READING 1111 1110
         0001 0000 |
 WRITING 0000 0010
         0001 0010
```

- toggle the reading and writing flags, leaving other flags unchanged
```c
device = device ^ (READING | WRITING);
device ^= READING | WRITING;
```

```c
Example 1: device is initially 0001 0001

          initial 0001 0001 ^
READING | WRITING 0000 0011
                  0001 0010

Example 2: device is initially 0001 0010
          initial 0001 0010 ^
          READING 0000 0001
                  0001 0011
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


```
16 bit value: 1101 1111 1010 1100
      result: 0000 0000 0000 0000


first iteration of the loop (i = 0):

16 bit value: 1101 1111 1010 1100
 read mask:   1000 0000 0000 0000 = 1u << 15
       AND:   1000 0000 0000 0000 <- if the first bit is set, we get something that isnt 0

write mask:   0000 0000 0000 0001 = 1u << 0

if ((value & read_mask) != 0) {
    result = result | write_mask;
    // result |= write_mask;
}

result after first iteration:  0000 0000 0000 0001

second iteration of the loop (i = 1):

    value:   1001 1111 1010 1100
read mask:   0100 0000 0000 0000 = 1u << 14
      AND:   0100 0000 0000 0000 <- if the first bit is set, we get something that isnt 0

write mask:  0000 0000 0000 0010 = 1u << 1
if ((value & read_mask) != 0) {
    result = result | write_mask;
    // result |= write_mask;
}

on the ith iteration of the loop:
write_mask


result after second iteration: 0000 0000 0000 0001
read_mask =  1u << (N_BITS - 1 - i);
write_mask = 1u << i;
```


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
