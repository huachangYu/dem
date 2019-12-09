#include <string>
class Cat
{
private:
    std::string age;
public:
    Cat(std::string age);
    ~Cat();
    std::string get_age();
};

Cat::Cat(std::string age)
{
    this->age=age;
}

Cat::~Cat()
{
}
std::string Cat::get_age(){
    return age;
}