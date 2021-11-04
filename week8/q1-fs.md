# Q1: File system structure

We say that the Unix filesystem is tree-structured, with the directory called / as the root of the tree.

![fs-diagram](filesystem.png)

### What is the full pathname of COMP1521's web directory?
/home/cs1521/web

### Which directory is ~jas/../..?
The `~` symbol often relates to home directories.

Using a `~` by itself will take you to your own home directory, while using `~` with another username takes you to their home directory.

`..` takes you up the tree to the parent directory.

Therefore, we end up at the root directory (`/`).

### Links to the children of a given directory are stored as entries in the directory structure. Where is the link to the **parent** directory stored?

We use `../` to store a link to the parent directory.

We use `./` as a link to the current directory.

### What kind of filesystem object is cat?
cat is just a regular file.
We can use:
* `ls -l`
* `stat`
* `file`
to find out more about a file.

### What kind of filesystem object is home?
`/home` is a directory (more commonly known as folders).

### What kind of filesystem object is tty0?
`/dev` stands for device and provides as with a way to interact with different devices as if they were just files.

`/dev/tty0` refers specifically to a device which we can interact with as if it were a character special file. A character special file represents an interface which we can write and read **bytes** from.

tty stands for a tele-typewriter. A teletypewriter was essentially a physical terminal.

### What kind of filesystem object is a symbolic link? What value does it contain?
A symbolic link contains a link to another file system object within our file system. The symbolic link contains a path to the object it points to.

### Symbolic links change the filesystem from a tree structure to a graph structure. How do they do this.

