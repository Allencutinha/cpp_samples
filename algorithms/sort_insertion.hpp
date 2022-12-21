#pragma once

#include <iostream>
#include <vector>

// Insertion sort is a simple sorting algorithm that works by iterating through
// a list and inserting each element into its proper position in the sorted
// portion of the list. The algorithm works as follows:

// Start with the second element in the list.
// Get the value of the current element.
// Get the index of the previous element.
// While the value of the current element is less than the value of the previous
// element and we haven't reached the beginning of the list: Shift the previous
// element one position to the right. Update the index of the previous element.
// Insert the current element into its proper position.
// Repeat the process for the next element in the list.
// The algorithm continues until it has iterated through the entire list. At the
// end, the list will be sorted in ascending order.

// Insertion sort has a time complexity of O(n^2), which means that it takes
// longer to sort larger lists. However, it is relatively simple to implement
// and can be efficient for small lists or lists that are nearly sorted.

void insertionSort(std::vector<int> &vec) {
    if (vec.size() > 0) {
        // Iterate through the list, starting at the second element
        for (int i = 1; i < vec.size(); i++) {
            // Get the value of the current element
            int value = vec[i];
            // Get the index of the previous element
            int j = i - 1;
            // While the value of the current element is less than the value of
            // the previous element and we haven't reached the beginning of the
            // list
            while (j >= 0 && vec[j] > value) {
                // Shift the previous element one position to the right
                vec[j + 1] = vec[j];
                // Update the index of the previous element
                j--;
            }
            // Insert the current element into its proper position
            vec[j + 1] = value;
        }
    }
}

namespace insertion_sort {
int test() {
    std::vector<int> vec = {5, 2, 4, 1, 3};
    insertionSort(vec);
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
} // namespace insertion_sort
