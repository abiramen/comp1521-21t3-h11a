// Non-recursive solution
#include <stdio.h>

int main(void) {
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}

// A recursive, albeit non-idiomatic solution
#include <stdio.h>
#define LENGTH 10

void print_array(int nums[], int index, int length) {
    if (index >= length) return;
    printf("%d\n", nums[index]);
    print_array(nums, index + 1, length);
}

int main(void) {
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array(nums, 0, LENGTH);
}

// A nicer recursive solution which only takes two parameters.
#include <stdio.h>
#define LENGTH 10

void print_array(int nums[], int length) {
    // Each recursive call is provided a SUB-ARRAY, with any already-printed
    // elements not included.
    if (length <= 0) return;
    printf("%d\n", nums[0]);
    // We use &nums[1] to get a new sub-array with the first element excluded.
    // For example,
    //  nums    = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3}
    // &nums[1] = {1, 4, 1, 5, 9, 2, 6, 5, 3}
    print_array(&nums[1], length - 1);
}

int main(void) {
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array(nums, LENGTH);
}
