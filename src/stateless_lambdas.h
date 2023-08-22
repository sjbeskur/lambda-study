#include <iostream>
#include <vector>

/*
    int y = 55;
    auto stateful_display = [y](int x)
    { std::cout << x; };

    /// the above "display" lambda basically gets converted to the following:

    class CrypticCompilerGeneratedName
    {
    public:
        CrypticCompilerGeneratedName(int y) : y_(y);

        void operator()(int x)
        {
            std::cout << x + y;
        }
    }
    /// ^^ this is still stateless

*/

void statefull_lambda()
{

    std::string name = "Batmans age is: ";

    // notice that the capture list is not empty
    auto lambda = [name](int age)
    { std::cout << name << age << std::endl; };

    lambda(29);
}
