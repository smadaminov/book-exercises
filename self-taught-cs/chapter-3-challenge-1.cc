/*
 * Chapter 3 Challenge 1
 *
 * Given the list of words in alphabetical order, write a function that performs
 * a binary search for a word and returns whether it is in the list.
 *
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool contains_word(const std::vector<std::string>& words, const std::string& word) {
    typedef std::vector<std::string>::size_type vec_sz;

    vec_sz left = 0;
    vec_sz right = words.size() - 1;
    vec_sz mid = (left + right) / 2;

    while(right - left > 1) {
        if (words[mid].compare(word) == 0) {
            return true;
        }
        else if (words[mid].compare(word) < 0) {
            left = mid;
            mid = (left + right) / 2;
        }
        else {
            right = mid;
            mid = (left + right) / 2;
        }
    }

    return (words[left].compare(word) == 0 || words[right].compare(word) == 0);
}

void run_fruit_test(const std::vector<std::string>& fruits) {
    assert(contains_word(fruits, "apricot") == true);
    std::cout << "Passed 'apricot' test!" << std::endl;
    assert(contains_word(fruits, "banana") == true);
    std::cout << "Passed 'banana' test!" << std::endl;
    assert(contains_word(fruits, "orange") == true);
    std::cout << "Passed 'orange' test!" << std::endl;
    assert(contains_word(fruits, "peach") == true);
    std::cout << "Passed 'peach' test!" << std::endl;

    assert(contains_word(fruits, "agava") == false);
    std::cout << "Passed 'agava' test!" << std::endl;
    assert(contains_word(fruits, "apple") == false);
    std::cout << "Passed 'apple' test!" << std::endl;
    assert(contains_word(fruits, "blueberry") == false);
    std::cout << "Passed 'blueberry' test!" << std::endl;
    assert(contains_word(fruits, "melon") == false);
    std::cout << "Passed 'melon' test!" << std::endl;
    assert(contains_word(fruits, "papaya") == false);
    std::cout << "Passed 'papaya' test!" << std::endl;
    assert(contains_word(fruits, "pineapple") == false);
    std::cout << "Passed 'pineapple' test!" << std::endl;

    if (fruits.size() == 5) {
        assert(contains_word(fruits, "persimmon") == true);
        std::cout << "Passed 'persimmon' test!" << std::endl;
    }
}

int main(void) {
    std::vector<std::string> fruits = {"apricot", "banana", "orange", "peach"};
    run_fruit_test(fruits);
    fruits.push_back("persimmon");
    run_fruit_test(fruits);

    return 0;
}
