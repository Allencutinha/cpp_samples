#include <gtest/gtest.h>
#include "add.hpp"


TEST(AddTest, Positive) {
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(3, 4), 7);
}

TEST(AddTest, Negative) {
  EXPECT_EQ(add(-1, -2), -3);
  EXPECT_EQ(add(-3, -4), -7);
}

TEST(AddTest, Zero) {
  EXPECT_EQ(add(0, 0), 0);
  EXPECT_EQ(add(1, -1), 0);
}