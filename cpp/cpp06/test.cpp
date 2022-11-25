#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>

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
    std::string hi = "+inf";
    char *num;
    float temp = std::strtod(hi.data(), &num);
    double ttemp = std::strtod(hi.data(), &num);
    
    std::cout << num << std::endl;
    std::cout << ttemp << std::endl;

    int ok = std::atol("-9999999999999999999999");
    long yes = std::strtol("9999999999999999999", NULL, 10);
    std::cout << ok << std::endl;
    std::cout << yes << std::endl;

    
    return 0;
}