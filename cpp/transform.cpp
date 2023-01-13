#include <algorithm>
#include <array>
#include <functional>
#include <gtest/gtest.h>

TEST(TransformTest, TestSquareTransform)
{
    // Define a vector of integers
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> o = {1, 2, 3, 4, 5};
    std::vector<int> exp_o = {1, 4, 9, 16, 25};
    // Define a lambda function that takes an integer as input and returns its
    // square
    auto square = [](int x) { return x * x; };

    // Use the lambda function to square each element in the vector
    std::transform(v.begin(), v.end(), o.begin(), square);

    EXPECT_EQ(o, exp_o);
}

TEST(TransformTest, TestSquareTransformLambda)
{
    // Define a vector of integers
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> o = {1, 4, 9, 16, 25};

    // Use the lambda function to square each element in the vector
    std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * x; });

    EXPECT_EQ(v, o);
}

// Test the basic functionality of std::transform by transforming a simple range
// of integers using a lambda function that increments each element by 1.

TEST(TransformTest, BasicFunctionality)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected_output = {2, 3, 4, 5, 6};
    std::vector<int> output(input.size());
    std::transform(input.begin(), input.end(), output.begin(), [](int x) { return x + 1; });
    EXPECT_EQ(output, expected_output);
}

// Test the behavior of std::transform when using a function object as the
// transformation function.
struct IncrementByOne {
    int operator()(int x) const { return x + 1; }
};

TEST(TransformTest, FunctionObject)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected_output = {2, 3, 4, 5, 6};
    std::vector<int> output(input.size());
    std::transform(input.begin(), input.end(), output.begin(), IncrementByOne());
    EXPECT_EQ(output, expected_output);
}

// Test the behavior of std::transform when using a function pointer as the
// transformation function.

TEST(TransformTest, FunctionPointer)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected_output = {2, 3, 4, 5, 6};
    std::vector<int> output(input.size());
    std::transform(input.begin(), input.end(), output.begin(), IncrementByOne());
    EXPECT_EQ(output, expected_output);
}

// Test the behavior of std::transform when using a different type for the
// output range than the input range.

TEST(TransformTest, DifferentOutputType)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<double> expected_output = {1.5, 2.5, 3.5, 4.5, 5.5};
    std::vector<double> output(input.size());
    std::transform(
        input.begin(), input.end(), output.begin(), [](int x) { return static_cast<double>(x) + 0.5; });
    EXPECT_EQ(output, expected_output);
}

// Test the behavior of std::transform when the input and output ranges are the
// same.

TEST(TransformTest, SameInputAndOutputRange)
{
    std::vector<int> range = {1, 2, 3, 4, 5};
    std::vector<int> expected_output = {2, 3, 4, 5, 6};
    std::transform(range.begin(), range.end(), range.begin(), [](int x) { return x + 1; });
    EXPECT_EQ(range, expected_output);
}

// Test the behavior of std::transform when the input range is empty.

TEST(TransformTest, EmptyInputRange)
{
    std::vector<int> input;
    std::vector<int> output;
    std::transform(input.begin(), input.end(), output.begin(), [](int x) { return x + 1; });
    EXPECT_TRUE(output.empty());
}

// Test the behavior of std::transform when the input and output ranges are
// reversed.
TEST(TransformTest, ReversedInputAndOutputRanges)
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected_output = {2, 3, 4, 5, 6};
    std::vector<int> output(input.size());
    std::transform(input.rbegin(), input.rend(), output.rbegin(), [](int x) { return x + 1; });
    EXPECT_EQ(output, expected_output);
}
