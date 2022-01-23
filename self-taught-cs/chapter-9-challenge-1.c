/*
 * Chapter 9 Challenge 1
 *
 * Given the array called `an_array` of non-negative integers, return an array
 * consisting of all the even elements of `an_array`, followed by all the odd
 * elements of `an_array`.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t* array_splitter(uint64_t* an_array, size_t len) {
    uint64_t* result = (uint64_t*)calloc(len, sizeof(uint64_t));
    if (result == NULL) {
        printf("Cannot allocate memory!");
        return NULL;
    }

    size_t left_cursor = 0;
    size_t right_cursor = len - 1;
    for (size_t i = 0; i != len; ++i) {
        if (i % 2 == 0) {
            result[left_cursor++] = an_array[i];
        }
        else {
            result[right_cursor--] = an_array[i];
        }
    }

    return result;
}

int main(void) {
    uint64_t array_1[1] = {2};
    uint64_t* result_1 = array_splitter(array_1, 1);
    for (size_t i = 0; i < 1; ++i) {
        printf("%ld ", result_1[i]);
    }
    printf("\n");
    free(result_1);

    uint64_t array_2[4] = {1, 2, 3, 4};
    uint64_t* result_2 = array_splitter(array_2, 4);
    for (size_t i = 0; i < 4; ++i) {
        printf("%ld ", result_2[i]);
    }
    printf("\n");
    free(result_2);

    uint64_t array_3[5] = {1, 2, 3, 4, 5};
    uint64_t* result_3 = array_splitter(array_3, 5);
    for (size_t i = 0; i < 5; ++i) {
        printf("%ld ", result_3[i]);
    }
    printf("\n");
    free(result_3);

    return 0;
}
