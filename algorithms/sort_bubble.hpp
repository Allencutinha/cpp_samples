#pragma once

#include <iostream>
#include <vector>

// Bubble sort is a simple sorting algorithm that works by repeatedly iterating
// through a list and comparing adjacent elements. If two adjacent elements are
// in the wrong order (i.e., the first element is greater than the second
// element), they are swapped. This process is repeated until the list is fully
// sorted.

// Bubble sort has a time complexity of O(n^2), which means that it takes longer
// to sort larger lists. However, it is relatively simple to implement and can
// be useful in certain situations, such as when the list is nearly sorted or
// when the elements are small and can be compared quickly.

// Overall, bubble sort is not generally considered to be the most efficient
// sorting algorithm, as there are many other algorithms that have a faster time
// complexity. However, it can be a useful algorithm to know and can be useful
// in certain situations

void bubbleSort(std::vector<int> &vec) {
    if (vec.size() > 0) {
        // Iterate through the list n-1 times
        for (int i = 0; i < vec.size() - 1; i++) {
            // Compare adjacent elements and swap them if they are in the wrong
            // order
            for (int j = 0; j < vec.size() - i - 1; j++) {
                if (vec[j] > vec[j + 1]) {
                    std::swap(vec[j], vec[j + 1]);
                }
            }
        }
    }
}

namespace {
int test() {
    std::vector<int> vec = {5, 2, 4, 1, 3};
    bubbleSort(vec);
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
} // namespace
