/*
 * Chapter 4 Challenge 1
 *
 * Research and write a sorting algorithm that is not a bubble sort, insertion
 * sort, or merge sort.
 *
 */

#include <iostream>
#include <vector>

typedef std::vector<int>::size_type int_vec_sz;

template<class T>
bool is_sorted(const T &array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }

    return true;
}

template<class T>
void print_array(const T &array) {
    std::cout << "Array:";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;
}

void shell_sort(std::vector<int> &array) {
    int_vec_sz max_index = array.size();
    int_vec_sz gap = max_index / 2;

    std::cout << "Gap: " << gap << std::endl;
    while (gap != 0) {
        for (int_vec_sz i = 0; i < gap; ++i) {
            for (int_vec_sz n = i; n < max_index; n += gap) {
                for (int_vec_sz j = i; j < max_index - gap; j += gap) {
                    if (array[j] > array[j + gap]) {
                        std::swap(array[j], array[j + gap]);
                    }
                }
            }
        }
        std::cout << gap << "-sorted array" << std::endl;
        print_array(array);
        gap /= 2;
    }
}


int main(void) {
    std::vector<int> small_numbers = {3, 5, 2, 6, 1, 4, 8, 9, 7};
    std::cout << "Before sorting\n";
    print_array(small_numbers);
    shell_sort(small_numbers);
    std::cout << "After sorting\n";
    print_array(small_numbers);
    if (is_sorted(small_numbers)) {
        std::cout << "The array is sorted!\n";
    }
    else {
        std::cout << "The array is not sorted!\n";
    }

    return 0;
}
