#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
    /* data */
public:
    Entity(std::string text)
    {

        std::cout << text << std::endl;
    }

    ~Entity()
    {
        std::cout << "entity destroyed\n"
                  << std::endl;
    }

    void print(std::string text)
    {
        std::cout << text << std::endl;
    }
};

int main(int argc, char const *argv[])
{

    std::shared_ptr<Entity> e_copy;

    // scope 1 (contains unique pointer)
    {
        //  initialize new unique pointer
        std::unique_ptr<Entity> entity_unique = std::make_unique<Entity>("entity_unique initialized");
        entity_unique->print("this is entity_unique print function");
        //  initialize new shared pointer
    }


    // scope 2 (contains shared pointer & the copy)
    {
        std::shared_ptr<Entity> entity_shared = std::make_shared<Entity>("entity_shared initialized");
        entity_shared->print("this is entity_shared print function");
        e_copy = entity_shared;
    }


    // scope 3 (contains call for print inside copy pointer)
    {
        e_copy->print("this is entity copy print function");
    }

    
    return 0;
}
