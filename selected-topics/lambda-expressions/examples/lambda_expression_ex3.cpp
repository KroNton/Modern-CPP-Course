#include <iostream>
#include <vector>
#include <algorithm>

/*
lambda expression
an unnamed function object capable of capturing variables in scope

Basic syntax: [captures]  (params) {body}
*/

int main(int argc, char const *argv[])
{

    std::vector<int> my_vect{1, 3, 4, 7, 8, 2};

    // using lambda by storing function object in a varible
    int last_Result = -1;
    int last_Result2 = -2;
/*
can use " & "  so compiler will capture all variables 

can use  "&last_Result, &last_Result2" pass py refrence for one by one to make it more secure
*/
    auto print_v_1 = [&](int element)
    {   last_Result= element;
        last_Result2= element;
        std::cout << element << " "; };

    auto print_v_2 = [&last_Result, &last_Result2](int element)
    {   last_Result= element;
        last_Result2= element;
        std::cout << element << " "; };

    std::cout << "lambda function output:" << std::endl;

    std::for_each(my_vect.begin(), my_vect.end(), print_v_2);

    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << " last result:" << last_Result << std::endl;
    std::cout << " last result2:" << last_Result2 << std::endl;

    return 0;
}
