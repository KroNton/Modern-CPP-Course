#include <iostream>
#include <vector>
#include <algorithm>

/*
lambda expression
an unnamed function object capable of capturing variables in scope

Basic syntax: [captures]  (params) {body}
*/
// lambda is translated to this
struct print_functor
{
    int lastResult{-1};
    void operator()(int n)
    {
        lastResult=n;
        std::cout << n << " ";
    }
};

int main(int argc, char const *argv[])
{

    std::vector<int> my_vect{1, 3, 4, 7, 8, 2};


    // using lambda by storing function object in a varible
    int last_Result = -1;
    
    auto print_v = [&](int element)
    {   last_Result=element;
        std::cout << element << " "; };

    std::cout << "lambda function output:" << std::endl;

    std::for_each(my_vect.begin(), my_vect.end(), print_v);

    std::cout << std::endl;

    std::cout << " functor output:" << std::endl;

    std::for_each(my_vect.begin(), my_vect.end(), print_functor());

    std::cout << std::endl;
    std::cout << " last result:" << last_Result<<std::endl;
    return 0;
}
