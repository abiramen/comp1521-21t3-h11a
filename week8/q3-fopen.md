# Q3-5: fopen

### What does fopen do? What are its parameters?
fopen opens a file and provides a pointer to a file stream.
We can interact with a file stream by using other library functions.
- fgets
- fgetc
- fputs
- fputc

fopen takes a pathname to the file we want to open, as well as a mode.

The mode defines how we want to interact with the file. We can find out more about modes at `man 3 fopen`.

### What are some circumstances it may return NULL?
fopen returns NULL if there is an error.

We can errors for various reasons, including:
- if the mode is invalid
- if malloc is out of memory
- don't have permission to access a file
- if the file doesn't exist, and we've told it not to create the file

### How do you print the specific reason it returned NULL?

We can:
- use perror in order to print the error string
- we can use the value of the errno global variable
- strerror gives you the same string that perror prints out
