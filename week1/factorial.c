#include <stdio.h>

int factorial(int n);

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
}

// n! = n * (n - 1)!
// 4! = 4 * 3 * 2 * 1
//    = 4 * 3!
// 3! = 3 * 2!
// 2! = 2 * 1!
// 1! = 1 * 0!
// 0! = 1 <- base case
//

int factorial(int n) {
    if (n == 0) { // base case
        return 1;
    }
    return n * factorial(n - 1); // recursive case
}

// factorial(2):
// 2 * 1 = 2
//      factorial(1):
//      1 * 1 = 1
//              factorial(0):
//                  1
