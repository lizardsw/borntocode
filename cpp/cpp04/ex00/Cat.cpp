#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "🐱Cat constructor🐱" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "🐱Cat copy constructor🐱" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "🐱Cat copy assignment🐱" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "🐱Cat destructor🐱" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱🐱🐱 miaw miaw miaw 🐱🐱🐱🐱" << std::endl;
}
