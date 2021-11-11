// Write a C program, chmod_if_public_write.c, which is given 1+ command-line
// arguments which are the pathnames of files or directories.

// If the file or directory is publically-writeable, it should change it to be
// not publically-writeable, leaving other permissions unchanged.

// It also should print a line to stdout as per the example below.

/*******************************************************************************
 $ dcc chmod_if_public_write.c -o chmod_if_public_write
 $ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xrwx 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--rw- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c
$ ./file_modes file_modes file_modes.c file_sizes file_sizes.c
removing public write from file_sizes
file_sizes.c is not publically writable
file_modes is not publically writable
removing public write from file_modes.c
$ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xr-x 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--r-- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

void chmod_if_needed(char *pathname) {
    // statbuf contains a COPY of the metadata about the file
    struct stat statbuf;
    if (stat(pathname, &statbuf) != 0) {
        perror("stat");
        return;
    }

    if (statbuf.st_mode & S_IWOTH) {
        // file is publically writeable, so we need to fix that
        printf("removing public write from %s\n", pathname);
        // new_mode has public write removed
        mode_t new_mode = statbuf.st_mode & ~S_IWOTH;
        if (chmod(pathname, new_mode) != 0) {
            perror("chmod");
            return;
        }
    } else {
        printf("%s is not publically writable\n", pathname);
    }

}



