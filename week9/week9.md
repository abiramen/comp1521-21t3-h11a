## Assignment 👏 Review 👏

Let's talk about the assignment!

- What's in an egg?
- What's in the provided code? What functions do we need to fill out?
- How do we compile the provided code?

## stat and lstat

### Consider the following output from the command `ls -l ~cs1521`
```
         HARD LINKS         FILE
PERMISSIONS V   USER  GROUP SIZE  LAST MODIFY FILENAME
drwxr-x--- 11 cs1521 cs1521 4096 Aug 27 11:59 17s2.work
drwxr-xr-x  2 cs1521 cs1521 4096 Aug 20 13:20 bin
-rw-r-----  1 cs1521 cs1521   38 Jul 20 14:28 give.spec
drwxr-xr-x  3 cs1521 cs1521 4096 Aug 20 13:20 lib
drwxr-x--x  3 cs1521 cs1521 4096 Jul 20 10:58 public_html
drwxr-xr-x 12 cs1521 cs1521 4096 Aug 13 17:31 spim
drwxr-x---  2 cs1521 cs1521 4096 Sep  4 15:18 tmp
lrwxrwxrwx  1 cs1521 cs1521   11 Jul 16 18:33 web -> public_html
```

- Who can access the `17s2.work` directory?
    - By access, we want to know who can read and explore the directory.
        - the user (cs1521) can read, write and explore
        - the group (cs1521) can read and explore
        - anyone else cannot do anything with this directory

- What operations can a typical user perform on the `public_html` directory?
    - anyone else can explore `public_html`

- What is the file `web`?
    - this file has `l` as part of its mode
    - the `l` suggests that it is a symbolic Link 
        - a symbolic link points to another file
```
rwx rwx rwx

- `r` stands for Read
- `w` stands for Write
- `x` stands for eXecute / eXplore

- first triplet is the 'user' -> refers to permissions held by the user which owns the file (in this case, a user named cs1521)
- second triplet is for the 'group' -> refers to permissions held by the group which owns the file (in this case, a user named cs1521)
- third triplet is for anyone else -> refers to permissions held by users which aren't part of the group, or which aren't the user which owns the file
```

## `stat` and `lstat`
 
The `stat()` and `lstat()` functions both take an argument which is a pointer to a `struct stat` object, and fill it with the metadata for a named file.
 
On Linux, *some* of the fields in `struct stat` include:
 
```c
struct stat {
    ino_t st_ino;         /* inode number */
    mode_t st_mode;       /* protection */
    uid_t st_uid;         /* user ID of owner */
    gid_t st_gid;         /* group ID of owner */
    off_t st_size;        /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t st_blocks;   /* number of 512B blocks allocated */
    time_t st_atime;      /* time of last access */
    time_t st_mtime;      /* time of last modification */
    time_t st_ctime;      /* time of last status change */
};
```
- (time values are seconds since the 1 Jan 1970 00:00UTC)

We can find out more about these fields by using `man 7 inode`.

Let's take a look at a simple program which prints out the information from `stat` on `quality-content.txt`.

- File modes and permissions
    - last three octal digits of a file mode corresponds to the permissions
        - for example, in `0o644`
            - 110100100
            - rw-r--r--


- What is the difference between `stat("web", &info)` and `lstat("web", &info)`?
    If we have a symbolic link, i.e.
    ```
    lrwxrwxrwx  1 cs1521 cs1521   11 Jul 16 18:33 web -> public_html
    ```
        - using `stat("web", ...)` follows the symbolic link and gets information about `public_html`
        - using `lstat("web", ...)` gets us information about the symbolic link itself


## Write a C program which is given files as arguments, and makes the file not publically writeable if needed.

## The fictitious `msg` file format is used to encode a message up to 256 bytes long.

It consists of:
| Name           | Size                 | Description                                                 |
|----------------|----------------------|-------------------------------------------------------------|
| Header         | 3 bytes              | Every valid msg file contains the bytes `msg` at the start. |
| message-length | 1 byte               | The message length is encoded in one byte.                  |
| Message        | message-length bytes | This is the actual message.                                 |
| Footer         | 3 bytes              | Every valid msg file contains the bytes `end` at the end.   | 

Create a program which determines whether a given msg file is valid or not.

It should use the `fseek` function to skip past the message and check the footer.

### fseek's `whence` value
- SEEK_SET: relative to the start of the file
- SEEK_CUR: relative to where I am currently in the file
- SEEK_END: relative to the end of the file

## Lab notes for this week

- Make sure to use `stat` for the first lab exercise (you'll likely fail automarking otherwise).
- The strftime function, as well as other functions from time.h might be useful if you decide to try the final challenge.
