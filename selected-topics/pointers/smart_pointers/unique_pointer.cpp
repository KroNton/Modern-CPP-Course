#include <iostream>
#include <string>
#include <memory>

class UniquePointer
{
private:
    /* data */
public:
    UniquePointer(/* args */)
    {

        std::cout << "code initialized" << std::endl;
    }

    ~UniquePointer()
    {
        std::cout << "code destroyed" << std::endl;
    }

    void print(std::string text){
       std::cout << text << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
     // first way to initialize new unique pointer   
    std::unique_ptr<UniquePointer> entity1(new UniquePointer());
    
    // secound way to initialize new unique pointer
    std::unique_ptr<UniquePointer> entity2 = std::make_unique<UniquePointer>() ;

    entity1->print("this is entity1 print function");
    entity2->print("this is entity2 print function");

    return 0;
}
