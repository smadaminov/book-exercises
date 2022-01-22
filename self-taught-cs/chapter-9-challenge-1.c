/*
 * Chapter 9 Challenge 1
 *
 * Given the array called `an_array` of non-negative integers, return an array
 * consisting of all the even elements of `an_array`, followed by all the odd
 * elements of `an_array`.
 *
 */

uint64_t* array_splitter(uint64_t* an_array, size_t len) {
    uint64_t* result = (uint64_t*)calloc(len, sizeof(uint64_t));
    if (result == NULL) {
        printf("Cannot allocate memory!");
        return NULL;
    }

    size_t left_cursor = 0;
    size_t rigth_cursor = len - 1;
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

    return 0;
}
