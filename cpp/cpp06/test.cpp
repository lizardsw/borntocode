#include <iostream>
#include <cstdlib>


class Parent
{
public:
    Parent() { std::cout << "Parent " << std::endl; }
    virtual ~Parent() { std::cout << "~Parent " << std::endl; }

    void say()
    {
        std::cout << "parent say" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child() { std::cout << "Child " << std::endl; }
    virtual ~Child() { std::cout << "~Child " << std::endl; }

    void say()
    {
        std::cout << "Child say" << std::endl;
    }
};


int main()
{
    char *num;
    float temp = std::strtod("a", &num);
    std::cout << temp << num << std::endl;


    int ok = std::atol("-9999999999999999999999");
    long yes = std::strtol("9999999999999999999", NULL, 10);
    std::cout << ok << std::endl;
    std::cout << yes << std::endl;
    return 0;
}