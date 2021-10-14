#include <stdio.h>
#define N_ROWS 6
#define N_COLS 12


char flag[N_ROWS][N_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {
    int row = 0;
main__outer_cond:
    if (row >= 6) goto main__outer_after;
    int col = 0;
main__inner_cond:
    if (col >= 12) goto main__inner_after;
    printf("%c", flag[row][col]);
main__inner_step:
    col++;
    goto main__inner_cond;
main__inner_after:
    printf("\n");
main__outer_step:
    row++;
    goto main__outer_cond;
main__outer_after:
    return 0;
}
