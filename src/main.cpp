
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "dummy.hpp"
#include "multiplier.h"
#include "printer.h"

template <typename T>
void dump_vector(std::vector<T> &vec)
{
    for (auto i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void example_0()
{
    std::cout << "------------ example 0 ------------" << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::cout << "input list of numbers" << std::endl;
    dump_vector(numbers);

    Multiplier mult{3};
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), mult);
    std::cout << "after transform" << std::endl;
    dump_vector(numbers);

    // slightly less wordy but still tedious
    std::cout << "after another transform" << std::endl;
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), Multiplier(2));
    dump_vector(numbers);
}

void example_1()
{
    std::cout << "------------ example function objects ------------" << std::endl;
    Display<int> int_printer;
    Display<std::string> string_printer;

    int_printer(5150); // same as d1.operator(5150)
    std::cout << std::endl;
    string_printer("Seth is a bad mamma jamma"); // same as d2.operator("my string")
    std::cout << std::endl;
    // the above is ultimately still quite useless but demonstrates function objects

    // this is a bit more interesting:
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::cout << "list of numbers" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), int_printer);
    std::cout << std::endl;

    std::vector<std::string> names = {"fredy", "zane", "seth", "josh"};
    std::cout << "list of names" << std::endl;
    std::for_each(names.begin(), names.end(), string_printer);
    std::cout << std::endl;
}

void example_2()
{
    std::cout << "------------ example with lambdas  ------------" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<std::string> names = {"fredy", "rose", "seth", "john", "colin", "matt"};

    Display<int> int_printer;
    Display<std::string> string_printer;

    auto lambda = [](int x)
    { std::cout << x << " "; };

    std::for_each(numbers.begin(), numbers.end(), lambda);
    std::cout << std::endl;

    std::for_each(names.begin(), names.end(),
                  [](std::string x)
                  { std::cout << x << " "; });

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    example_0();
    std::cout << std::endl;

    example_1();
    std::cout << std::endl;

    example_2();
    std::cout << std::endl;
}
