#include <iostream>
#include <string>
#include <memory>

class UniquePointer
{
private:
    /* data */
public:
    UniquePointer(std::string text)
    {

        std::cout << text << std::endl;
    }

    ~UniquePointer()
    {
        std::cout << "entity destroyed" << std::endl;
    }

    void print(std::string text)
    {
        std::cout << text << std::endl;
    }
};

int main(int argc, char const *argv[])
{

    // first scope
    {
        // first way to initialize new unique pointer
        std::unique_ptr<UniquePointer> entity1(new UniquePointer("entity1 initialized")); // pass paramters to constructor
        entity1->print("this is entity1 print function");
       
    }

    // secound scope
    {
         // secound way to initialize new unique pointer(better one)
        std::unique_ptr<UniquePointer> entity2 = std::make_unique<UniquePointer>("entity2 initialized"); // pass paramters to constructor

        entity2->print("this is entity2 print function");
    }
    
    // std::cin.get();
    return 0;
}
