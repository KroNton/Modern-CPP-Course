// @file initialize.cpp
// g++ -std=c++17 1_initialize.cpp -o prog
#include <iostream>

int main(){

    int x = 7;
    int* x_ptr = &x; // pointer that points to the adress of x in the memory

    std::cout << "the value of x is: " << x << std::endl;
    std::cout <<"the value  of x_ptr is : "<< x_ptr<< std::endl;
    std::cout <<"the adress of x is : "<< &x<< std::endl;
    std::cout << "the adress of x_ptr is: " << &x_ptr << std::endl;
    std::cout << "the content of x_ptr is: " << *x_ptr << std::endl;
    
    return 0;
}