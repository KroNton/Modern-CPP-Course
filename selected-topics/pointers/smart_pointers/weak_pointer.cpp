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

    std::weak_ptr<Entity> e_copy; // just to check if the shared pointer still alive but it doesn't keep it alive 


    // scope 1 (contains shared pointer & the copy)
    {
        std::shared_ptr<Entity> entity_shared = std::make_shared<Entity>("entity_shared initialized");
        entity_shared->print("this is entity_shared print function");
        e_copy = entity_shared; 
    }



    
    return 0;
}
