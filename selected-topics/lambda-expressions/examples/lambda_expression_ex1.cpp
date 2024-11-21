#include <iostream>
#include <vector>
#include <algorithm>

/*
lambda expression
an unnamed function object capable of capturing variables in scope

Basic syntax: [captures ]  (params) { body }
*/

// we can replace this part with inline function(lambda function)
void print_func(int element)
{

    std::cout << element << " ";
}

int main(int argc, char const *argv[])
{

    std::vector<int> my_vect{1, 3, 4, 7, 8, 2};

    std::cout << "print_func output:" << std::endl;
    // using print_func
    std::for_each(my_vect.begin(), my_vect.end(), print_func);

    std::cout << std::endl;

    std::cout << "lambda function output:" << std::endl;

    // using lambda
    std::for_each(my_vect.begin(), my_vect.end(), [](int element)
                  { std::cout << element << " "; });

    std::cout << std::endl;

    // we can replace this part with "for_each"
    /*
    std::cout << "for loop output:" << std::endl;
    for (auto element : my_vect)
    {

        std::cout << element << " ";
    }

    std::cout << std::endl;
*/
    return 0;
}
