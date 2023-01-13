#pragma once

#include <iostream>
#include <vector>

// Function to merge two sorted halves of the array

// Here is a step-by-step breakdown of the merge function, which is used to
// merge two sorted halves of an array:

// The merge function is used to merge two sorted halves of an array into a
// single sorted array. It takes three arguments: the array to be sorted, the
// left index of the first half of the array, and the right index of the second
// half of the array.

// 1. Calculate the sizes of the two halves of the array using the left, middle,
// and right indices.
// 2. Create temporary arrays to hold the two halves of the array using the
// calculated sizes.
// 3. Copy the elements of the two halves into the temporary arrays.
// 4. Initialize three variables: i to 0, j to 0, and k to the left index.
// 5. While i is less than the size of the left half and j is less than the size
// of the right half:
//     1. If the i-th element of the left half is less than or equal to the j-th
//     element of the right half:
//         1. Set the k-th element of the original array to the i-th element of
//         the left half.
//         2. Increment i and k.
//     2. Otherwise:
//         1. Set the k-th element of the original array to the j-th element of
//         the right half.
//         2. Increment j and k.
// 6. If i is less than the size of the left half:
// 7. Set the remaining elements of the original array to the remaining elements
// of the left half.
// 8. If j is less than the size of the right half:
// 9. Set the remaining elements of the original array to the remaining elements
// of the right half.

void merge(std::vector<int>& arr, int left, int middle, int right)
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

// Here is a step-by-step breakdown of the iterative version of the merge sort
// algorithm:

// 1.Initialize the block size to 1 and the left index to 0.
// 2. While the block size is less than or equal to the size of the array:
//     1. Calculate the middle and right indices of the current block using the
//     left index, block size, and size of the array.
//     2. Merge the two sorted halves of the array using the merge function,
//     passing in the array, left index, middle index, and right index as
//     arguments.
//     3. Increment the left index by twice the block size.
// 3. When the block size is greater than the size of the array, the entire
// array is sorted.

// Iterative function to sort an array using merge sort
void merge_sort(std::vector<int>& arr)
{
    // Determine the size of the array
    int size = arr.size();

    // Iterate over the array with a block size ranging from 1 to the size of
    // the array
    for (int block_size = 1; block_size <= size; block_size *= 2) {
        // Iterate over the array with the current block size
        for (int left = 0; left < size; left += 2 * block_size) {
            // Calculate the middle and right indices
            int middle = std::min(left + block_size - 1, size - 1);
            int right = std::min(left + 2 * block_size - 1, size - 1);

            // Merge the two sorted halves
            merge(arr, left, middle, right);
        }
    }
}
namespace merge_sort_test {
int test()
{
    // Test the merge sort function
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    merge_sort(arr);

    // Print the sorted array
    for (int x: arr)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
} // namespace merge_sort_test