// @file sizeof.cpp
// Linked list example
// g++ -Wall -Wextra -std=c++17 2_sizeof.cpp -o prog
#include <iostream>

int main(){
    int x=7;
    int *x_ptr=&x;

    std::cout << "sizeof(int) is :" << sizeof(int) << " bytes" <<std::endl;

    std::cout << "sizeof(int *) is : " << sizeof(int *) << " bytes" <<std::endl;

    std::cout << "sizeof(x) is : " << sizeof(x) << " bytes" <<std::endl;

    std::cout << "sizeof(x_ptr) is : " << sizeof(x_ptr) << " bytes" <<std::endl;


    return 0;
}