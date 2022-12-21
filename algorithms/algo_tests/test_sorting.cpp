#include <gtest/gtest.h>
#include <vector>

#include "../sort_bubble.hpp"
#include "../sort_insertion.hpp"

TEST(BubbleSortTest, TestAscendingOrder) {
    std::vector<int> vec = {5, 2, 4, 1, 3};
    bubbleSort(vec);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestDuplicateElements) {
    std::vector<int> vec = {5, 2, 4, 1, 3, 3};
    bubbleSort(vec);
    std::vector<int> expected = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestNegativeNumbers) {
    std::vector<int> vec = {5, -2, 4, -1, 3};
    bubbleSort(vec);
    std::vector<int> expected = {-2, -1, 3, 4, 5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestSingleElement) {
    std::vector<int> vec = {5};
    bubbleSort(vec);
    std::vector<int> expected = {5};
    EXPECT_EQ(vec, expected);
}

TEST(BubbleSortTest, TestEmptyList) {
    std::vector<int> vec;
    bubbleSort(vec);
    std::vector<int> expected;
    EXPECT_EQ(vec, expected);
}


TEST(InsertionSortTest, TestAscendingOrder) {
  std::vector<int> vec = {5, 2, 4, 1, 3};
  insertionSort(vec);
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestDuplicateElements) {
  std::vector<int> vec = {5, 2, 4, 1, 3, 3};
  insertionSort(vec);
  std::vector<int> expected = {1, 2, 3, 3, 4, 5};
  EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestNegativeNumbers) {
  std::vector<int> vec = {5, -2, 4, -1, 3};
  insertionSort(vec);
  std::vector<int> expected = {-2, -1, 3, 4, 5};
  EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestSingleElement) {
  std::vector<int> vec = {5};
  insertionSort(vec);
  std::vector<int> expected = {5};
  EXPECT_EQ(vec, expected);
}

TEST(InsertionSortTest, TestEmptyList) {
  std::vector<int> vec;
  insertionSort(vec);
  std::vector<int> expected;
  EXPECT_EQ(vec, expected);
}
