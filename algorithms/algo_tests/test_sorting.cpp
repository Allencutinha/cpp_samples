#include <gtest/gtest.h>
#include <vector>

#include "../sort_bubble.hpp"
#include "../sort_insertion.hpp"
#include "../sort_merge.hpp"
#include "../sort_merge_recursive.hpp"

TEST(BubbleSortTest, TestAscendingOrder)
{
    std::vector<int> vec = {5, 2, 4, 1, 3};
    bubbleSort(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestDuplicateElements)
{
    std::vector<int> vec = {5, 2, 4, 1, 3, 3};
    bubbleSort(vec);
    std::vector<int> expected = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestNegativeNumbers)
{
    std::vector<int> vec = {5, -2, 4, -1, 3};
    bubbleSort(vec);
    std::vector<int> expected = {-2, -1, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestSingleElement)
{
    std::vector<int> vec = {5};
    bubbleSort(vec);
    std::vector<int> expected = {5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestEmptyList)
{
    std::vector<int> vec;
    bubbleSort(vec);
    std::vector<int> expected;
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestAscendingOrder)
{
    std::vector<int> vec = {5, 2, 4, 1, 3};
    insertionSort(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestDuplicateElements)
{
    std::vector<int> vec = {5, 2, 4, 1, 3, 3};
    insertionSort(vec);
    std::vector<int> expected = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestNegativeNumbers)
{
    std::vector<int> vec = {5, -2, 4, -1, 3};
    insertionSort(vec);
    std::vector<int> expected = {-2, -1, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestSingleElement)
{
    std::vector<int> vec = {5};
    insertionSort(vec);
    std::vector<int> expected = {5};
    EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestEmptyList)
{
    std::vector<int> vec;
    insertionSort(vec);
    std::vector<int> expected;
    EXPECT_EQ(vec, expected);
}

// non recursive mereg sort test
TEST(MergeSortTest, EmptyArray)
{
    std::vector<int> arr;
    merge_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElementArray)
{
    std::vector<int> arr = {5};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({5}));
}

TEST(MergeSortTest, TwoElementArray)
{
    std::vector<int> arr = {5, 2};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({2, 5}));
}

TEST(MergeSortTest, OddNumberOfElements)
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(MergeSortTest, EvenNumberOfElements)
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3, 7};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
}

TEST(MergeSortTest, RepeatedElements)
{
    std::vector<int> arr = {5, 2, 5, 6, 1, 3, 5};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 5, 5, 5, 6}));
}

TEST(MergeSortTest, SortedArray)
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(MergeSortTest, ReverseSortedArray)
{
    std::vector<int> arr = {6, 5, 4, 3, 2, 1};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(MergeSortTest, LargeRandomArray)
{
    std::vector<int> arr = {10, 5, 3, 8, 7, 6, 4, 2, 9, 1};
    merge_sort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

// recursive merge sort test

TEST(RecursiveMergeSortTest, EmptyArray)
{
    std::vector<int> arr;
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_TRUE(arr.empty());
}

TEST(RecursiveMergeSortTest, SingleElementArray)
{
    std::vector<int> arr = {5};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({5}));
}

TEST(RecursiveMergeSortTest, TwoElementArray)
{
    std::vector<int> arr = {5, 2};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({2, 5}));
}

TEST(RecursiveMergeSortTest, OddNumberOfElements)
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(RecursiveMergeSortTest, EvenNumberOfElements)
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3, 7};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
}

TEST(RecursiveMergeSortTest, RepeatedElements)
{
    std::vector<int> arr = {5, 2, 5, 6, 1, 3, 5};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 5, 5, 5, 6}));
}

TEST(RecursiveMergeSortTest, SortedArray)
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(RecursiveMergeSortTest, ReverseSortedArray)
{
    std::vector<int> arr = {6, 5, 4, 3, 2, 1};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6}));
}

TEST(RecursiveMergeSortTest, LargeRandomArray)
{
    std::vector<int> arr = {10, 5, 3, 8, 7, 6, 4, 2, 9, 1};
    rmerge_sort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}
