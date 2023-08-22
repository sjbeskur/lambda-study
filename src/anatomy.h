#include <iostream>
#include <vector>

// ANATOMY OF A LAMBDA and some examples
//
// []  () -> return_type specifiers { /* body */ }
//
// [] - the capture list - by value or by reference
// () - parameter list - comma separated list of parameters
// -> return_type  - often this can be ommited as the compiler can figure it out
// specifiers - again options ( mutable and constexpr)
// {} - function body

void most_basic_lambda()
{

    auto lambda = []()
    { std::cout << "This is about as basic as possible" << std::endl; };

    // here is how we can call it..
    lambda();

    []()
    { std::cout << "This is about as basic as possible" << std::endl; }();
    // or you could just put () at the end ---------------------------- ^
}

/// @brief
///
void next_most_basic_lambda()
{

    auto lambda = [](int x, int y)
    { return x * y; };

    // here is how we can call it..
    int area = lambda(2, 4);
    int area1 = lambda(55, 0);
    int area2 = lambda(25, 32);

    // here the "-> int" is redundant but explicitly defined
    auto lambdax = [](int x, int y) -> int
    { return x * y; };

    int areax = lambda(51, 50);
}
