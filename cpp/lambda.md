# Lambda function in C++

Lambda functions, also known as anonymous functions, are a convenient way to define functions inline in C++. They are useful for writing short, concise functions that are only needed in a specific context and are not intended to be used elsewhere in the program.

Here are 10 examples of lambda functions in C++:

A simple lambda function that takes no arguments and returns nothing:

```cpp
[](){
    std::cout << "Hello, world!" << std::endl;
}();
```
A lambda function that takes two arguments and returns their sum:
```cpp
[](int x, int y){
    return x + y;
}(10, 20);
```

A lambda function that captures a local variable by reference:
```cpp
int n = 10;
[&n](){
    n++;
    std::cout << "n = " << n << std::endl;
}();
```
A lambda function that captures a local variable by value:
```cpp
int m = 15;
[m](){
    std::cout << "m = " << m << std::endl;
}();
```
A lambda function that takes a function pointer as an argument:
```cpp
auto func = [](int (*fp)(int, int), int x, int y){
    return fp(x, y);
};
int result = func(std::max, 10, 20);
```
A lambda function that returns a function pointer:
```cpp
auto func = []() -> int (*)(int, int) {
    return std::max;
};
int (*fp)(int, int) = func();
int result = fp(10, 20);
```

A lambda function that uses a default argument value:
```cpp
auto func = [](int x, int y=10){
    return x + y;
};
int result = func(20);
```

A lambda function that takes a variable number of arguments using std::initializer_list:
```cpp
auto func = [](std::initializer_list<int> args){
    int sum = 0;
    for (int x : args) {
        sum += x;
    }
    return sum;
};
int result = func({1, 2, 3, 4, 5});

```

A lambda function that uses a generic lambda:
```cpp
auto func = [](auto x, auto y){
    return x + y;
};
int result1 = func(10, 20);
double result2 = func(1.5, 2.5);
```

A lambda function that is stored in a variable and called later:
```cpp
auto func = [](int x, int y){
    return x * y;
};
int result = func(10, 20);
```