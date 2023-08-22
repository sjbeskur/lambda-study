#include <iostream>
#include <vector>

/*
    auto display = [](int x) { std::cout << x; };

    /// the above "display" lambda basically gets converted to the following:

    class CrypticCompilerGeneratedName
    {
    public:
        CrypticCompilerGeneratedName();

        void operator()(int x)
        {
            std::cout << x;
        }
    }

    /// ^^ this is still stateless

*/

/// @brief
///
void slightly_more_interesting_lambda()
{

    const int length = {5};
    int num_list[length]{10, 12, 14, 16, 18};

    // inside the lambda we have no knowledge of external variables.. so we have to
    // pass them in explicitly.
    auto sum_lambda = [](int nums[], int length)
    {
        int total{0};
        for (int i = 0; i < length; i++)
        {
            total += nums[i];
        }
        return total;
    };

    std::cout << sum_lambda(num_list, length);
}

/// @brief
///
void ref_and_pointer_parameters_lambda()
{

    int amount = {100};

    auto drink_coffee = [](int &coffee, int amount_to_drink)
    {
        coffee -= amount_to_drink; //
    };

    drink_coffee(amount, 50);
    std::cout << "amount of coffee left: " << amount << std::endl;

    // a contrived example to show pointer parameters
    auto fill_coffee = [](int *coffee, int amount_to_fill) // *coffee is pointing to the address of the parameter being passed
    {
        *coffee += amount_to_fill; // remember to dereference
    };

    fill_coffee(&amount, 10); // address of operator
    std::cout << "amount of coffee after fill: " << amount << std::endl;
}

/// @brief
///
void auto_parameters_lambda()
{

    std::vector<int> int_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<float> float_list = {1.0, 2.2, 3.3, 4.4, 5.55, 6.67, 7.47, 8.89, 9.22, 10.101, 11.9, 12.07};

    auto sum = [](auto &list)
    {
        typename std::remove_reference<decltype(list)>::type::value_type total = 0; // is used to deduce the type of elements in the container.
        for (auto &i : list)
        {
            total += i;
        }
        return total;
    };

    sum(int_list);
    sum(float_list);
}
