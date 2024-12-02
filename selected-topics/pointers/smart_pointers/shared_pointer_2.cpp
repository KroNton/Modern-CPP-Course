#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
    /* data */
public:
    Entity(/* args */)
    {

        std::cout << "code initialized" << std::endl;
    }

    ~Entity()
    {
        std::cout << "code destroyed" << std::endl;
    }

    void print(std::string text){
       std::cout << text << std::endl; 
    }
};

void spinning(std::shared_ptr<Entity> entity_shared){
 entity_shared->print("i'm inside spinning");
}

int main(int argc, char const *argv[])
{

    
    //  initialize new shared pointer
    std::shared_ptr<Entity> entity_shared = std::make_shared<Entity>() ;


    entity_shared->print("this is entity_shared print function");

    // create  shared pointer and passing it as a paramter for spinning function 
    spinning(std::make_shared<Entity>());
    
    return 0;
}
