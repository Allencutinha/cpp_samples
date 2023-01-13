#pragma once

#include <iostream>
#include <vector>

// Function to merge two sorted halves of the array
void rmerge(std::vector<int>& arr, int left, int middle, int right)
{
    // Calculate the sizes of the two halves
    int size1 = middle - left + 1;
    int size2 = right - middle;

    // Create temporary arrays to hold the two halves
    std::vector<int> left_half(size1);
    std::vector<int> right_half(size2);

    // Copy the elements of the two halves into the temporary arrays
    for (int i = 0; i < size1; i++)
        left_half[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
        right_half[j] = arr[middle + 1 + j];

    // Merge the two halves back into the original array
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (left_half[i] <= right_half[j])
            arr[k++] = left_half[i++];
        else
            arr[k++] = right_half[j++];
    }

    // Copy any remaining elements from the left half, if any
    while (i < size1)
        arr[k++] = left_half[i++];

    // Copy any remaining elements from the right half, if any
    while (j < size2)
        arr[k++] = right_half[j++];
}

// Recursive function to sort an array using merge sort
void rmerge_sort(std::vector<int>& arr, int left, int right)
{
    if (left < right) {
        // Calculate the middle index
        int middle = left + (right - left) / 2;

        // Sort the left half of the array
        rmerge_sort(arr, left, middle);

        // Sort the right half of the array
        rmerge_sort(arr, middle + 1, right);

        // Merge the two sorted halves
        rmerge(arr, left, middle, right);
    }
}

namespace recursive_merge_sort {

int test()
{
    // Test the merge sort function
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    rmerge_sort(arr, 0, arr.size() - 1);

    // Print the sorted array
    for (int x: arr)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
} // namespace recursive_merge_sort