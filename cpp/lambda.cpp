#include <algorithm>
#include <array>
#include <functional>
#include <gtest/gtest.h>

TEST(LambdaTests, TestVoidLambda)
{
    int n = 0;
    auto func = [&n]() { n++; };
    func();
    func();
    EXPECT_EQ(n, 2);
}

TEST(LambdaTests, TestSumLambda)
{
    auto func = [](int x, int y) { return x + y; };
    EXPECT_EQ(func(1, 2), 3);
    EXPECT_EQ(func(10, 20), 30);
    EXPECT_EQ(func(-1, -2), -3);
}

TEST(LambdaTests, TestCaptureByRefLambda)
{
    int n = 0;
    auto func = [&n]() { n++; };
    func();
    func();
    EXPECT_EQ(n, 2);
}

int add(int x, int y)
{
    return x + y;
}

int mul(int x, int y)
{
    return x * y;
}

TEST(LambdaTests, TestFuncPtrArgLambda)
{
    // Define a lambda function that takes a function object as an argument
    auto func = [](std::function<int(int, int)> fp, int x, int y) { return fp(x, y); };

    // Pass a function object to the lambda function
    EXPECT_EQ(func(add, 3, 4), 7);
    EXPECT_EQ(func(mul, 3, 4), 12);
}

TEST(LambdaTests, TestFuncPtrArgLambda2)
{
    using func_ptr_t = int (*)(int, int);
    auto func = [](func_ptr_t fp, int x, int y) { return fp(x, y); };
    EXPECT_EQ(func(mul, 3, 4), 12);
}

TEST(LambdaTests, TestGenericLambda)
{
    auto func = [](auto x, auto y) { return x + y; };
    EXPECT_EQ(func(10, 20), 30);
    EXPECT_EQ(func(1.5, 2.5), 4.0);
    EXPECT_EQ(func(1.5, 2), 3.5);
    EXPECT_EQ(func(1, 2.7), 3.7);
}

TEST(LambdaTests, TestLambdaInitializerList)
{
    auto func = [](std::initializer_list<int> args) {
        int sum = 0;
        for (int x: args) {
            sum += x;
        }
        return sum;
    };
    EXPECT_EQ(func({1, 2, 3, 4, 5}), 15);
    EXPECT_EQ(func({3, 4, 5}), 12);
    EXPECT_EQ(func({1, 4}), 5);
}
