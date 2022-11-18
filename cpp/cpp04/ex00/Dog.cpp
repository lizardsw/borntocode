#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "🐶Dog constructor🐶" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "🐶Dog copy constructor🐶" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "🐶Dog copy assignment🐶" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "🐶Dog destructor🐶" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶🐶🐶 bark bark bark 🐶🐶🐶🐶" << std::endl;
}