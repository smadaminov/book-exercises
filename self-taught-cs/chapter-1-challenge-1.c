/*
 * Chapter 2 Challenge 1
 *
 * Print the numbers from 1 to 10 recursively.
 *
 */

#include <stdio.h>

void recursive_print(int n) {
    if (n == 1) {
        printf("%d\n", n);
        return ;
    }
    else {
        printf("%d ", n);
        recursive_print(n - 1);
    }
}

int main(void) {
    int n = 10;
    recursive_print(n);

    return 0;
}
