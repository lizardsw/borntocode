#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "default";
	std::cout << "🐴Animal constructor🐴" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "🐴Animal copy constructor🐴" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "🐴Animal copy assignment🐴" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "🐴Animal destructor🐴" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "🐴🐴🐴no-type can't makesound!🐴🐴🐴" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}