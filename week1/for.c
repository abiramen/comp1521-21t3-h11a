#include <stdio.h>

int main(void) {
    // print every number from 1 to 10 inclusive with a while loop.
    int i = 1;  // initial value
    while (i <= 10 /* condition */) {
        printf("%d\n", i);
        i++; /* increment */
    }
    printf("%d\n", i);
    
    // print every number from 1 to 10 inclusive with a for loop.
    for (int j = 1; j <= 10; j++) {
        printf("%d\n", j);
    }
    // we cant do this since j stops existing
    // printf("%d\n", j);

    // you can be evil and use a for loop exactly like a while loop.
    // DONT DO THIS IT IS BAD STYLE :D
    // int i = 1;  // initial value
    // for (; i <= 10 /* condition */;) {
    //     printf("%d\n", i);
    //     i++; /* increment */
    // }
    // printf("%d\n", i);

    return 0;
}
