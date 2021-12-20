#include<stdio.h>

int bitcount(unsigned x){
    int count;

    for (count = 0; x != 0; x >>= 1){
        if (x & 1){
            count++;
        }
    }

    return count;
}

int main(void){
    int x = 11;

    printf("Number of bits in binary representation of %d is %d\n", x, bitcount(x));

    return 0;
}
